*This project has been created as part of the 42 curriculum by vpoka.*

# CPP00 — Classes and Basic I/O

A C++98 project from the 42 curriculum introducing object-oriented programming with classes, member functions, and C++ I/O streams.

## Table of contents

- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [What this project demonstrates](#what-this-project-demonstrates)
- [Technical constraints](#technical-constraints)
- [Repository structure](#repository-structure)
- [Focus areas by exercise](#focus-areas-by-exercise)
- [Testing](#testing)
- [Status](#status)

## Description

CPP00 is the first module of the 42 C++ Common Core sequence. The goal is to get comfortable with classes and object-oriented thinking while staying inside the C++98 standard. The three exercises grow steadily from plain command-line output to interactive classes and, finally, to reconstructing a class from its interface and a reference log.

This module is split into three exercises:

* **ex00 — Megaphone**
  Print command-line arguments in uppercase, or a loud feedback-noise message when no arguments are given.
* **ex01 — My Awesome PhoneBook**
  An interactive phone book with `ADD`, `SEARCH`, and `EXIT` commands that stores up to 8 contacts and displays them in fixed-width columns.
* **ex02 — The Job Of Your Dreams**
  Recreate a deleted `Account.cpp` from the provided `Account.hpp`, `tests.cpp`, and reference log, so the program's output matches the log exactly.

| Exercise | Executable | Main concepts |
| --- | --- | --- |
| [ex00](ex00/) — Megaphone | `megaphone` | `argv`, `std::string`, `std::toupper` |
| [ex01](ex01/) — My Awesome PhoneBook | `phonebook` | classes, encapsulation, `std::getline`, `<iomanip>` |
| [ex02](ex02/) — The Job Of Your Dreams | `account` | static members, `const`, initialization lists, timestamps |

## Instructions

### Prerequisites

- A C++ compiler available as `c++`, supporting `-std=c++98`.
- GNU Make and standard Unix shell utilities. The Makefiles use `-Wall -Wextra -Werror -std=c++98` (with `-MD -MP` dependency tracking); no external libraries are required.
- For the ex02 comparison snippet below: `sed` and `diff`.

The repository does not specify minimum compiler or Make versions.

### Build

Run these commands from the repository root. Each exercise has its own Makefile; there is no root Makefile.

```bash
make -C ex00
make -C ex01
make -C ex02
```

Each Makefile provides `all`, `clean` (remove build files), `fclean` (also remove the executable), and `re` (rebuild). For example:

```bash
make -C ex00 clean
make -C ex01 fclean
make -C ex02 re
```

ex01 and ex02 additionally provide `run` (build, then start the program):

```bash
make -C ex01 run
make -C ex02 run
```

### ex00 — Megaphone

From the repository root:

```bash
./ex00/megaphone "shhhhh... I think the students are asleep..."
./ex00/megaphone Damnit " ! " "Sorry students, I thought this thing was off."
./ex00/megaphone
```

Every argument is uppercased and printed to standard output **without separators** between arguments, followed by a single newline. The examples above produce:

```text
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

With no arguments the program prints `* LOUD AND UNBEARABLE FEEDBACK NOISE *` instead.

### ex01 — My Awesome PhoneBook

From the repository root:

```bash
make -C ex01 run
# or, after building:
./ex01/phonebook
```

The program takes no arguments and is fully interactive. It starts empty and shows the `PhoneBook>> ` prompt in a loop. It accepts exactly three commands:

- **ADD** — saves a new contact. The fields are prompted one at a time in this order: first name, last name, nickname, darkest secret, phone number. Empty fields are rejected and re-prompted, so a saved contact never has empty fields. The phone book holds at most 8 contacts in a fixed array (dynamic allocation is forbidden); a 9th contact replaces the oldest one.
- **SEARCH** — displays the saved contacts as a table of four columns (index, first name, last name, nickname). Each column is 10 characters wide, right-aligned, separated by `|`, and text longer than the column is truncated with its last character replaced by a dot (`.`). The program then prompts for an index and prints every field of that contact, one per line.
- **EXIT** — quits the program; the contacts are not persisted.
- Anything else prints an error message listing the accepted commands, and the prompt continues.

### ex02 — The Job Of Your Dreams

From the repository root:

```bash
make -C ex02 run
# or, after building:
(cd ex02 && ./account)
```

`account` takes no arguments. It runs the fixed scenario from the subject-provided `ex02/src/tests.cpp` (eight accounts are created, deposits and withdrawals are applied, and account/aggregate statuses are printed) and writes the log to standard output. Each line is prefixed with a `[YYYYMMDD_HHMMSS]` timestamp.

The output is meant to match the subject-provided reference log `ex02/19920104_091532.log` exactly, apart from timestamps:

```bash
make -C ex02
(cd ex02 && ./account | sed 's/^\[[^]]*\] //') > /tmp/account_out.txt
sed 's/^\[[^]]*\] //' ex02/19920104_091532.log > /tmp/account_ref.txt
diff /tmp/account_ref.txt /tmp/account_out.txt
```

## Resources

- **cppreference C++ reference:** entries for `std::string`, `<iomanip>` (`std::setw`, `std::setfill`), `std::toupper`, and `std::strftime`. Consult the C++98 behavior when reading modern documentation.
- **cplusplus.com references for [std::string](http://www.cplusplus.com/reference/string/string/) and [`<iomanip>`](http://www.cplusplus.com/reference/iomanip/)** — the pages recommended by the subject for ex01.
- **The C++98 standard (ISO/IEC 14882:1998)** — the language subset the whole module is limited to.
- **GNU Make manual:** targets, rules, and automatic variables used by the Makefiles.
- **42 subject, C++ Module 00 (version 9.1)** — supplied alongside the module repositories in the parent directory of this checkout.

### AI usage

AI was used to help write and improve this README and project documentation, prepare commits, and, where output or data visualisation is more complex, tweak that output.

## What this project demonstrates

* C++98 development under strict compilation rules (`-Wall -Wextra -Werror -std=c++98`)
* Designing small classes with private state and a clear public interface
* Formatted console I/O with `<iostream>` and `<iomanip>`
* Line-based interactive input and validation with `std::getline`
* Static class members, `const` member functions, and initialization lists
* Reimplementing a class so its output matches a reference log field by field

## Technical constraints

This project is developed under the 42 C++ module rules:

* Standard: **C++98** — the code must still compile with `-std=c++98`
* Compiler flags: **`-Wall -Wextra -Werror`**
* External libraries, Boost, and C++11 or later features are forbidden; so are `*printf()`, `*alloc()`, and `free()`
* `using namespace` and `friend` are forbidden unless explicitly stated
* STL containers and `<algorithm>` are not allowed before Modules 08 and 09 — the exercise-provided `ex02/src/tests.cpp` is the only file here that uses them
* ex01 forbids dynamic allocation for contacts: the phone book is a fixed array of 8 with round-robin replacement
* Function implementations in headers are forbidden (function templates excepted); headers must be self-contained and use include guards
* Memory allocated with `new` must not leak
* The Orthodox Canonical Form is only required from Module 02 onward, so it is not mandated in this module

## Repository structure

```text
cpp00/
├── README.md
├── ex00/   # Megaphone: src/megaphone.cpp, Makefile
├── ex01/   # My Awesome PhoneBook: src/{Contact,PhoneBook,main}.cpp,
│           #                        include/{Contact,PhoneBook}.hpp, Makefile
└── ex02/   # The Job Of Your Dreams: src/Account.cpp, include/Account.hpp, Makefile
    ├── src/tests.cpp          # Test scenario provided by the subject
    └── 19920104_091532.log    # Reference output provided by the subject
```

## Focus areas by exercise

### ex00 — Megaphone

* iterating over `argv` and printing to standard output
* character-wise `std::string` manipulation
* uppercasing with `std::toupper`
* one-shot output with a trailing newline

### ex01 — My Awesome PhoneBook

* two collaborating classes (`PhoneBook`, `Contact`) with private attributes and getters/setters
* fixed-capacity storage that overwrites the oldest contact
* empty-field rejection and full-line input with `std::getline`
* right-aligned, truncated, `|`-separated columns with `std::setw` / `std::setfill`

### ex02 — The Job Of Your Dreams

* static data members and static accessors (`getNbAccounts`, `getTotalAmount`, …)
* initialization lists and `const` member functions
* timestamp formatting with `std::strftime`
* matching a reference log exactly in wording, field order, and separators

## Testing

### ex02 — The Job Of Your Dreams

The exercise ships with a real test scenario (`ex02/src/tests.cpp`) and a reference log (`ex02/19920104_091532.log`). Build, run, and compare with the timestamps stripped, as shown in [Instructions](#ex02--the-job-of-your-dreams). A clean diff means the recreated `Account.cpp` behaves like the original.

Two differences are expected and not errors: the timestamps always differ (the snippet strips them), and the eight `closed` lines may appear in reverse order depending on the compiler and operating system.

### ex00 and ex01

There are no automated test scripts in the repository; these two programs are exercised by hand (ex00 with the examples above, ex01 interactively).

## Status

* **Status:** Completed
* **Final grade:** **100/100 points**
