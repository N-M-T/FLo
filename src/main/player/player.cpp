/***************************************************************************
**                                                                        **
**  Fixation Logger (FLo)                                                 **
**                                                                        **
**  Copyright (C) 2017-2018 Neil Thomas                                   **
**  All rights reserved.                                                  **
**                                                                        **
**  This file is part of the FLo.                                         **
**                                                                        **
**  The FLo is free software: you can redistribute it and/or modify       **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Neil Thomas                                          **
**          Contact: neil.thomas@uni.cumbria.ac.uk                        **
**             Date: 22.05.17                                             **
**          Version: 1.0.0-beta                                           **
****************************************************************************/

#include "player.h"

Player::Player(QObject *parent)
 : QThread(parent)
{
    stop = true;
}

bool Player::loadVideo(string filename)
{
    capture = new cv::VideoCapture(filename);

    if (capture->isOpened())
    {
        emitCurrentFrame();
        return true;
    }
    else
        return false;
}

//emits one frame at a time for left/right and just loaded video functions
void Player::emitCurrentFrame()
{
    if(getCurrentFrame()<getNumberOfFrames())
    {
        capture->read(frame);
        if (frame.channels()== 3)
        {
            cvtColor(frame, RGBframe, CV_BGR2RGB);
            img = QImage((const unsigned char*)(RGBframe.data),
                        RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
        }
        else
        {
            img = QImage((const unsigned char*)(frame.data),
                         frame.cols,frame.rows,QImage::Format_Indexed8);
        }
        emit processedImage(img); //sends the image frame to mainwindow
        emit currentTime(getCurrentFrame()/getFrameRate()); //sends the current time to mainwindow
        //emit currentFrame(getCurrentFrame());
    }
}

void Player::Play()
{
    if (!isRunning())
    {
        if (isStopped())
        {
            stop = false;
        }
        start(LowPriority);
    }
}

//plays the video in real-time
void Player::run()
{
    int delay = (1000/getFrameRate());
    while(!stop)
    {
        if (!capture->read(frame))
        {
            stop = true;
        }

        if (frame.channels()== 3)
        {
            cvtColor(frame, RGBframe, CV_BGR2RGB);
            img = QImage((const unsigned char*)(RGBframe.data),
                        RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
        }
        else
        {
            img = QImage((const unsigned char*)(frame.data),
                         frame.cols,frame.rows,QImage::Format_Indexed8);
        }
        emit processedImage(img); //sends the image frame to mainwindow
        emit currentTime(getCurrentFrame()/getFrameRate()); //sends the current time to mainwindow
        //emitCurrentFrame();
        this->msleep(delay);
    }
}

void Player::right()
{
    emitCurrentFrame();
}

void Player::left()
{
    if(getCurrentFrame() > 0)
    {
        setCurrentFrame(getCurrentFrame()-2);
        emitCurrentFrame();
    }
}

double Player::getCurrentFrame()
{
    return capture->get(CV_CAP_PROP_POS_FRAMES);
}

double Player::getNumberOfFrames()
{
    return capture->get(CV_CAP_PROP_FRAME_COUNT);
}

double Player::getFrameRate()
{
    return (int)capture->get(CV_CAP_PROP_FPS);
}

void Player::setCurrentFrame(int frameNumber)
{
    capture->set(CV_CAP_PROP_POS_FRAMES, frameNumber);
}

Player::~Player()
{
    mutex.lock();
    stop = true;
    capture->release();
    delete capture;
    condition.wakeOne();
    mutex.unlock();
    wait();
}

void Player::Stop()
{
    stop = true;
}

void Player::msleep(int ms)
{
    struct timespec ts =
    {
        ms / 1000, (ms % 1000) * 1000 * 1000
    };

    nanosleep(&ts, NULL);
}

bool Player::isStopped() const
{
    return this->stop;
}
