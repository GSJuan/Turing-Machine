# Turing-Machine
## Autor: Juan García Santos alu0101325583 
### Español:
Simulador de Máquina de turing

Requisitos: Tener instalado y actualizado cmake y gdb
```bash
sudo apt-get update
sudo apt-get install build-essential gdb
sudo apt install cmake
```

- Comandos de compilación (ejecutados desde el directorio en el que se encuentra este README):
```bash
cmake -B build
cmake --build build --config Debug --target all --
```

- Comando de ejecución de ejemplo
```bash
./build/TuringMachine
```

NOTA: Si se quisiera añadir otro fichero de definicion de automata para probar, se debe arrastrar a la carpeta 'test'.
Una vez hecho eso, simplemente ejecute el programa dandole el nombre del archivo como parámetro usando la opción -f <nombre de fichero>.
El programa está codificado para que las rutas de los archivos de definición de autómatas esten fijados a ese directorio.
Por ello, es necesario que el archivo se encuentre en el directorio y solo pase como argumento el nombre del mismo, no su ruta.

Códigos de error:
 + 1 - Error en la apertura de archivo de definición de autómata
 + 2 - Autómata definido incorrectamente