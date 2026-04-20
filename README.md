# Mini Search Engine (C++)

A simple yet powerful command-line (Gathering the courage to create an interface) search engine built in C++, featuring multi-word search, TF-IDF ranking, and persistent indexing.

---

## Features

* Multi-word search (AND logic)
* TF-IDF based ranking system
* Persistent index (saved to disk)
* Fast search using inverted index
* Text normalization (case-insensitive and punctuation removal)
* Reindex command to update data

---

## How It Works

The engine builds an inverted index, mapping each word to the files where it appears, along with its frequency.

Search results are ranked using a simplified TF-IDF approach:

* TF (Term Frequency): how many times a word appears in a document
* IDF (Inverse Document Frequency): gives more importance to rare words

This allows the engine to return more relevant results first, similar to real-world search systems.

---

## Usage

* Search:

```id="7e6n3g"
hello world
```

* Reindex:

```id="a0l5cu"
reindex
```

* Exit:

```id="g8r9pn"
exit
```

---

## Example Output

```
Results for 'hello world':
- file1.txt (score: 1.82)
- file2.txt (score: 0.91)
```

---

## Technologies

* C++
* STL (map, set, vector)
* File I/O
* Basic Information Retrieval concepts

---

# Motor de Busca Simples (C++)

Um motor de busca em linha de comando (criando coragem para fazer uma interface) desenvolvido em C++, com suporte a múltiplas palavras, ranking por relevância (TF-IDF) e persistência de dados.

---

## Funcionalidades

* Busca por múltiplas palavras (lógica AND)
* Ranking baseado em TF-IDF
* Índice persistente (salvo em arquivo)
* Busca rápida com índice invertido
* Normalização de texto (sem distinção de maiúsculas/minúsculas)
* Comando de reindexação

---

## Como Funciona

O sistema constrói um índice invertido, associando cada palavra aos arquivos em que aparece, incluindo sua frequência.

Os resultados são ordenados usando TF-IDF:

* TF: frequência da palavra no documento
* IDF: importância da palavra baseada em sua raridade

Isso permite retornar resultados mais relevantes primeiro.

---

## Uso

* Buscar:

```id="4vyl9h"
hello world
```

* Reindexar:

```id="w3e4nt"
reindex
```

* Sair:

```id="c8kzbm"
exit
```

---

## Exemplo

```id="z8e5gk"
Resultados para 'hello world':
- file1.txt (score: 1.82)
- file2.txt (score: 0.91)
```

---
