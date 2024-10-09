# 📜 get_next_line

Este proyecto es parte del **currículum de 42** y su objetivo es implementar la función `get_next_line`, que permite leer una línea de un archivo descriptor cada vez que es llamada, manteniendo el estado entre llamadas.

## 🚀 Archivos del proyecto

El repositorio contiene los siguientes archivos clave para el funcionamiento del proyecto:

- `get_next_line.c`: Contiene la implementación principal de la función `get_next_line`.
- `get_next_line.h`: Archivo de cabecera con las definiciones de las funciones y estructuras utilizadas en el proyecto.
- `get_next_line_utils.c`: Funciones auxiliares utilizadas por `get_next_line`.
- `get_next_line_bonus.c`: Implementación para la versión **bonus**, permitiendo manejar múltiples descriptores de archivo.
- `get_next_line_bonus.h`: Archivo de cabecera para la versión **bonus**.
- `get_next_line_utils_bonus.c`: Funciones auxiliares adicionales para la versión **bonus**.

## 📖 Uso del proyecto

Puedes clonar el repositorio y compilar los archivos utilizando el compilador de tu preferencia. Aquí tienes un ejemplo de cómo compilar el proyecto con `gcc`:

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o get_next_line
```

Para la versión **bonus**:

```bash
cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus
```

## 📚 Consulta la Wiki

Para más información sobre cómo utilizar cada función, así como ejemplos prácticos, consulta la [wiki del repositorio](https://github.com/Marcos03BR/get_next_line/wiki) 📘. Ahí encontrarás explicaciones detalladas.
