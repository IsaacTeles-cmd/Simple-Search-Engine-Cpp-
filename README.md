# Simple Search Engine (C++)

A simple command-line search engine built in C++. It indexes words from text files and allows users to search for terms, returning the files where those words appear.

## Features

* Inverted index structure (word → list of files)
* Case-insensitive search
* Basic punctuation removal
* Multiple file indexing
* Interactive search loop
* Fast lookup using `std::map` and `std::set`

## How to Use

1. Place your text files in the same directory as the program.
2. In the code, define which files will be indexed:

   ```cpp
   engine.indexFile("file1.txt");
   engine.indexFile("file2.txt");
   ```
3. Run the program.
4. Type a word to search.
5. The program will display which files contain that word.
6. Type **exit** to close the program.

## Example

```
--- SEARCH ENGINE ---

What do you want to search for? (or type 'exit' to quit): hello
The word 'hello' it was found in the following files:
- file1.txt
- file2.txt
---------------------------------------
```

---

# Motor de Busca Simples (C++)

Um motor de busca simples em linha de comando desenvolvido em C++. Ele indexa palavras de arquivos de texto e permite que o usuário pesquise termos, retornando os arquivos onde essas palavras aparecem.

## Funcionalidades

* Estrutura de índice invertido (palavra → lista de arquivos)
* Busca sem distinção entre maiúsculas e minúsculas
* Remoção básica de pontuação
* Indexação de múltiplos arquivos
* Loop interativo de busca
* Busca rápida usando `std::map` e `std::set`

## Como Usar

1. Coloque os arquivos de texto na mesma pasta do programa.
2. No código, defina quais arquivos serão indexados:

   ```cpp
   engine.indexFile("file1.txt");
   engine.indexFile("file2.txt");
   ```
3. Execute o programa.
4. Digite uma palavra para buscar.
5. O programa mostrará em quais arquivos a palavra foi encontrada.
6. Digite **exit** para encerrar o programa.

## Exemplo

```
--- SEARCH ENGINE ---

O que você deseja buscar? (ou digite 'exit' para sair): hello
A palavra 'hello' foi encontrada nos seguintes arquivos:
- file1.txt
- file2.txt
---------------------------------------
```
