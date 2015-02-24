# EFI Brainfuck 

## What is EFI Brainfuck? 

EFI Brainfuck is, as the name implies, a Brainfuck interpreter for Extensible
Firmware Interface (EFI) and it's successor, Universal Extensible Firmware 
Interface (UEFI).

## How do I build EFI Brainfuck?

 1. Install [GNU-EFI](http://sourceforge.net/projects/gnu-efi/)
 2. Run 'make'.

## How do I run EFI Brainfuck? 

Like any EFI program. Place it on the EFI system partition and launch it. 

A few suggestions on _how_ to launch *EFI Brainfuck*: 
 * Manually create a boot menu entry in your system ("CMOS") setup.
 * Use the UEFI Shell. 
 * Add it to the boot list via `efibootmgr`

## Credits

 * malloc implementation from [efilinux](https://github.com/mfleming/efilinux/), 
 Copyright (c) 2011, Intel Corporation

