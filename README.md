# Arancino

Arancino is dynamic protection framework that can be used to defend Intel Pin against anti-instrumentation attacks.
Arancino is a research project developed at [NECSTLab](http://necst.it).

## Research Paper

We present the findings of this work in a research paper:

**Measuring and Defeating Anti-Instrumentation-Equipped Malware**  
Mario Polino, Andrea Continella, Stefano D’Alessio, Lorenzo Fontana, Fabio Gritti, Sebastiano Mariani, and Stefano Zanero
*In Proceedings of the Conference on Detection of Intrusions and Malware and Vulnerability Assessment (DIMVA), July 2017*

[[PDF](https://conand.me/publications/polino-arancino-2017.pdf)]

If you use *Arancino* in a scientific publication, we would appreciate citations using this **Bibtex** entry:
``` tex
@InProceedings{polino_arancino_2017,
  author     = {Polino, Mario and Continella, Andrea and Mariani, Sebastiano and D’Alessio, Stefano and Fontata, Lorenzo and Gritti, Fabio and Zanero, Stefano},
  title      = {{Measuring and Defeating Anti-Instrumentation-Equipped Malware}},
  booktitle  = {{Proceedings of the Conference on Detection of Intrusions and Malware and Vulnerability Assessment (DIMVA)}},
  location   = {{Bonn, Germany}},
  date       = {2017},
}
```

## Introduction

Dynamic Binary Instrumentation (DBI) Tools are useful in malware analysis.
However, DBI frameworks are not completely transparent to the analyzed malware, and, in fact, anti-instrumentation techniques have been developed to detect the instrumentation process.
We classified such anti-instrumentation techniques in four categories:

* **Code Cache Artifacts.** These techniques aim at detecting artifacts that are usually inherent of a DBI cache. For example, the Instruction Pointer is different if a binary is instrumented.
In fact, in a DBI Tool the code is usually executed from a different memory region, called code cache, rather than from the main module of the binary.

* **Environment Artifacts.** The memory layout of an instrumented binary is deeply different respect to the one of a not instrumented one.
Searching for DBI artifacts such as strings or particular code patterns in memory can eventually reveal the presence of a DBI tool inside the target process memory.
Also, the parent process of an instrumented binary is often the DBI tool itself.

* **JIT Compiler Detection.** JIT compilers make a lot of noise inside the process in terms of Windows API calls and pages allocation.
These artifacts can be leveraged by the instrumented program to detect the presence of a DBI tool.

* **Overhead Detection.** Instrumentation adds an observable overhead in the execution of the target program.
This overhead can be noticed by malware samples by estimating the execution time of a particular set of instructions.

Our approach leverages the complete control that a DBI Tool has on the instrumented binary to hide the artifacts that the DBI tool itself introduces during the instrumentation process.
In fact, by instrumenting a binary, we can identify when it tries to leverage such artifacts to evade the analysis.
In practice, we designed a set of countermeasures for the anti-instrumentation techniques we described above.

On top of Arancino, we implemented a generic, anti-instrumentation-resilient unpacker.

## Dataset release

In the spirit of open science we are happy to release our datasets to the community.
You can find our data [here](https://drive.google.com/drive/folders/0BzARZokQgFezVWlBWnZfLUFTX0E?usp=sharing).

## Automated Arancino

In order to automate the analysis of malware samples, we also developed a lightweight analysis framework, which we release [here](https://github.com/necst/automated-arancino).
