# Game of Life

C++ implementation of Conway's Game of Life, a zero-player game based on the evolution of a set of cells arranged in a grid. This grid has an initial random arrangement of living and dead cells and changes according to two rules:

- Any live cell with two or three neighbors survives.
- Any dead cell with three live neighbors becomes a live cell.
- All other live cells die in the next generation. Similarly, all other dead cells stay dead.

## Compilation

To compilate the program, run `make` command:

    $ make

## Execution

Execute:

    $ make run

### Usage

Dimensions for the board will be requested by keyboard. With that input, a random cell arrangement will be generated. It is necessary to enter a number of turns to observe and study the board's evolution.

## Cleaning

Run to delete executables and object files:

    $ make clean

## References

[Conway's Game of Life | Wikipedia](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/LuismGH/Game-of-Life.

## License

This program is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).
