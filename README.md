# Simple Blockchain in C++

This project is a basic implementation of a blockchain using C++ and object-oriented programming principles. It demonstrates how blockchain technology works by creating a chain of blocks, each containing data and a cryptographic hash of the previous block. This example uses the SHA-256 algorithm for hashing, provided by the OpenSSL library.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Introduction

A blockchain is a distributed ledger technology that maintains a continuously growing list of records, called blocks, which are linked and secured using cryptographic hashes. Each block contains a cryptographic hash of the previous block, a timestamp, and transaction data.

This project provides a simple, educational implementation of a blockchain in C++.

## Features

- Basic blockchain structure with linked blocks.
- SHA-256 hashing for block validation.
- Simple data integrity check.

## Prerequisites

- Embarcadero Dev-C++ (or any C++ compiler)
- OpenSSL library

## Installation

### Setting Up Embarcadero Dev-C++ and OpenSSL

1. **Download and Install Embarcadero Dev-C++:**
   - Download and install from [Embarcadero's website](https://www.embarcadero.com/products/dev-cpp).

2. **Download and Install OpenSSL:**
   - Download OpenSSL from [Win32 OpenSSL](https://slproweb.com/products/Win32OpenSSL.html).
   - Install OpenSSL to a directory (e.g., `C:\OpenSSL-Win32`).

3. **Configure Dev-C++ for OpenSSL:**
   - Open Dev-C++.
   - Go to `Tools` -> `Compiler Options`.
   - Under the `Settings` tab, click `Linker` and then `Add Library or Object`.
     - Add `libssl.a` and `libcrypto.a` from your OpenSSL installation directory (e.g., `C:\OpenSSL-Win32\lib`).
   - Go to `Settings` -> `Compiler` and click the `Directories` tab.
     - Under `Include Directories`, add the path to OpenSSL headers (e.g., `C:\OpenSSL-Win32\include`).
     - Under `Library Directories`, add the path to OpenSSL libraries (e.g., `C:\OpenSSL-Win32\lib`).

### Cloning the Repository

Clone this repository to your local machine using:
```sh
git clone https://github.com/yourusername/BlockchainProject.git
