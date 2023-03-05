# Tic Tac Toe in SFML
Simple Tic Tac Toe clone made in SFML.

## Why tf did I make this game???
I made this game 'cause there was no internet in my house for a week so I had to do something to keep myself sane.

---

The game was made using an SFML wrapper library I made as a side project. The wrapper library is available as well at this URL: https://www.github.com/reallySmooll/TTT.

## Building
**NOTE: I don't really know if you can build on systems different than Linux, 'cause the project uses pkg-conf to search for SFML on the system. I guess you could read up on the Meson docs and see if you can pass in a pkg-conf binary or something like that. I don't really know I'm sorry, I don't use Windows anymore so I don't know if you can, you'll just have to look it up by yourself.**

### Dependencies
Now that we have the NOTE out of the way, there are some dependencies which you will need to install to build this project:

- Meson (the build system)
- Ninja (`make` but stealthy. Get it? 'Cause ninjas are stealthy?)
- SFML (the graphics library)
- git (if you don't have it already than install it 'cause it's needed not only for this project but for any open source project that you want to use)
- A C++ compiler
- And that's about it. I don't think there's anything else that you need, but if there is, just install it it's not that hard.

### Actually building this abomination
The only thing you need to do is:

```
$ git clone https://github.com/reallySmooll/tic-tac-toe-sfml.git
$ cd tic-tac-toe-sfml
$ meson setup build
$ meson compile -C build
```

That's it. And if you want to run it:

```
$ build/Tic\ Tac\ Toe.x86_64
```

**Why those backslashes? It's because there are spaces in the executables name. If you'd like to change it, edit the `meson.build` file and edit the exe variable.**

And that's it. You are playing Tic Tac Toe made in SFML.

---

If you're wondering why the resolution is 800x600, it's because I set it at the beginning and never changed it back. And also Tic Tac Toe doesn't really require a big resolution. It's Tic Tac Toe ffs.

## Third Party Resources Used in the Project
`04B_30` Font - 04
