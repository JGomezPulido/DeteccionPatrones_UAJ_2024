set OpenCVBuild=.\Dependencies\opencv\build\x64\vc16\bin
set bin=.\bin\
mkdir %bin%

COPY /y %OpenCVBuild%\opencv_videoio_ffmpeg490_64.dll %bin%
COPY /y %OpenCVBuild%\opencv_videoio_msmf490_64.dll %bin%
COPY /y %OpenCVBuild%\opencv_videoio_msmf490_64d.dll %bin%
COPY /y %OpenCVBuild%\opencv_world490.dll %bin%
COPY /y %OpenCVBuild%\opencv_world490d.dll %bin%
