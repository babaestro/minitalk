# minitalk

# Minitalk

Minitalk is a project at 42 school that challenges students to create a small data exchange program using UNIX signals. The project consists of two main components: a client and a server.

## Key Features

- Uses UNIX signals (SIGUSR1 and SIGUSR2) for communication
- Implements a client-server architecture
- Converts messages to binary for transmission
- Handles various character types, including emojis and non-ASCII characters

## Technical Aspects

- Signal handling using signal() or sigaction() functions
- Process ID (PID) management
- Bit-by-bit message transmission
- Character to binary conversion and vice versa
- Error handling and input validation

## Compilation

To compile the project, use the provided Makefile:

```bash
make
```

This will generate two executables: `client` and `server`.

## Usage

1. Start the server:
   ```bash
   ./server
   ```
   The server will display its PID.

2. In a separate terminal, run the client:
   ```bash
   ./client <server_pid> "<message>"
   ```
   Replace `<server_pid>` with the server's PID and `<message>` with your desired text.

## Example

```bash
./server
# Server displays: Server PID: 12345

# In another terminal
./client 12345 "Hello, Minitalk!"
```

The server will receive and display the message "Hello, Minitalk!" character by character.

## Skills Developed

- Interprocess communication (IPC)
- Signal handling in C
- Binary operations and bitwise manipulation
- Process synchronization
- Error management in C programming

Minitalk provides hands-on experience with UNIX signals and low-level communication protocols, enhancing students' understanding of system programming concepts.
