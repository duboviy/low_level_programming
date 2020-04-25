Strings
=======

```rust
// Create a string from a literal
let hello: &'static str = "Hello!";
let hello2: &str = "Hello!";

// Create an owned string
let owned_hello: ~str = ~"Hello!";

// Create a managed string
let managed_hello: @str = @"Hello!";

// Mutable owned string
// There are no mutable string slices
let mut buf : ~str = ~"Hello";
buf.push_str(", world!");

// Convert a string to its representation as bytes
// It's impossible to convert back
let hello_as_bytes: &[u8] = "hello!".as_bytes();

// Create a &[u8] using a byte literal
let hello_as_bytes2: &[u8] = bytes!("hello");

// Take a slice of a string
let hello_slice: &str = hello.slice(0, 3);
let owned_hello_slice: &str = owned_hello.slice(0, 3);
```

The [std::str](http://static.rust-lang.org/doc/master/std/str/index.html) documentation is also quite good.


Vectors
=======

```rust

// Create a fixed size vector
let x : [uint, ..10] = [5, ..10]
// [5, 5, 5, 5, 5, 5, 5, 5, 5, 5]

// There are no fixed size strings in Rust.

// Create a variable size owned vector
let mut numbers : ~[uint]= ~[0, 1, 2];

// Create a variable size
let mut numbers : &[uint]= &[0, 1, 2];

// Do some other thing
let mut xs = [0, ..10]; 
for (i, r) in range(0, 10).zip(xs.mut_iter()) { *r = i; } 
xs;
// [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
```

See also [std::vec](http://static.rust-lang.org/doc/master/std/vec/index.html)


### Making a mutable vector

```rust
let mut numbers: [int] = [0, 1, 2]; 
numbers[1] = 2; 
numbers; /// [0, 2, 2]

let mut numbers: &[int] = [0, 1, 2];
numbers[1] = 2; // error: in this example numbers are mutable, not the vector it points to
```

Functions
=========

Basically `fn()` is the only function type you want. `*fn()` is a type, but it doesn't make sense to use it, and `~fn()`, `&fn()`, `@fn()` are not types.

For a function using the C calling convention, use `extern "C" fn()`. The part in quotes signifies the calling convention.

For an explanation of function types, see [Fn types in Rust](http://smallcultfollowing.com/babysteps/blog/2013/10/10/fn-types-in-rust/)

Structs
=======

Make a packed struct using: 

```rust
# [packed]
struct IDTPointer {
    limit: u16,
    base: u32
}
```

Exporting things
================

* `main` is always exported
* You *can't* export global variables. 
* You can export other functions, but only in libraries

For a function to be exported, it should look like

```rust
# [no_mangle]
pub fn x() {
}
```

and then you need to compile `example_foo.rs` with the `--lib` flag
