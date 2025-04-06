# custom-instruction

This project demonstrates how to simulate custom RISC-V instructions using inline assembly in C++.

##How to Build

###Install RISC-V toolchain:

```bash
sudo apt install g++-riscv64-linux-gnu qemu-user
```
Compile using the Makefile:

```bash
make heron
```

Or manually:

```bash
riscv64-linux-gnu-g++ -static -march=rv64gc -mabi=lp64d -o heron heron.cpp
```

Run with QEMU:

```bash
qemu-riscv64 ./heron
```
