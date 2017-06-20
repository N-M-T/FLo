## Synopsis

Fixation Logger (FLo) is a simple Linux GUI application allowing users to import video sequences superimposed with gaze fixations recorded from eye tracking equipment, and log features frame-by-frame by a single key press. It is built on C++ with Qt.

## Motivation

During one of my PhD investigations, I needed to log gaze allocations on a frame-by-frame basis from previously recorded video sequences. A free application with the ability to map identified features to specific keys certainly speeds up such a process. Hence, I wrote FLo.

## Installation

Feel free to compile the source code on your own machine. To do this you will need git and qt5. Then type the following into a terminal:

sudo git clone https://github.com/N-M-T/FLo <br />
mkdir FLo/build <br />
cd FLo/build <br />
sudo qmake ~/FLo/fixationLogger.pro <br />
sudo make

## Instructions

The GUI was designed to be simple and intuitive. File > open will prompt the user to load a video file. The video can be played or rewound, or moved forward or back frame-by-frame using the media buttons and/or slider. The slider isn't particularly responsive so be patient on longer videos.  <br />

![ScreenShot](https://github.com/N-M-T/FLo/blob/master/screenshots/Screenshot%20from%202017-05-22%2011-51-40.png)  <br />

Features > Enter features will open a dialog box where you can enter fixated features within the video. <br />

![ScreenShot](https://github.com/N-M-T/FLo/blob/master/screenshots/Screenshot%20from%202017-05-22%2011-59-04.png) <br />

These will then appear in the bottom right of the main window.

![ScreenShot](https://github.com/N-M-T/FLo/blob/master/screenshots/Screenshot%20from%202017-05-22%2012-01-38.png)
<br />

Note that the number of the feature now corresponds to its counterpart on your keyboard. Pressing the number will log a fixation of that particular feature and then move one frame forward in the video sequence. In cases where no gaze data were recorded due to blinking or sampling errors, pressing the right key in the main window will log as no fixation. Alternatively, you can delete previously logged fixated features and move back one frame by using the left key in the main window. Whilst fixations are being logged it is not possible to use the slider to seek through the video as this would disrupt the current feature logging method. Also note that currently it is not possible to add more features after the logging process has started - doing so will refresh the data thus deleting any previous logging. This will be amended soon. <br />

Finally, Analyse > Basic will show each fixated feature, and the number and duration of fixations on that feature. Duration expressed as a percentage of the duration of video analysed is also provided. <br />

![ScreenShot](https://github.com/N-M-T/FLo/blob/master/screenshots/Screenshot%20from%202017-05-22%2012-14-46.png) <br />

## License

FLo is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.
