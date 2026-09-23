#!/bin/bash

# Compilar el documento LaTeX
pdflatex -interaction=nonstopmode memoria.tex
pdflatex -interaction=nonstopmode memoria.tex

# Limpiar archivos auxiliares
rm -f *.aux *.log *.out *.toc 