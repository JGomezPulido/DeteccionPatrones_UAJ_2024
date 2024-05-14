Para hacer el setup del proyecto:
- Descargarse el instalador de OpenCV 4.9.0 y extraer en Dependencies/ (en la raíz del proyecto)
- Copiar las dll de opencv_world490 y opencv_world490d (estaran en Dependencies/opencv/build/x64/vc16/bin/) a una carpeta bin/ en la raíz del proyecto
- En las propiedades del proyecto en Visual, en propiedades de depuracion, cambiar el directorio de trabajo a $(OutDir)