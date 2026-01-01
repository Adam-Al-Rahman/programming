use std::fs::File;
use std::io::{self, BufRead, BufReader, BufWriter, Write};

fn solve<R: BufRead, W: Write>(scan: &mut Scanner<R>, out: &mut W) {
    let a: i64 = scan.next();
    let b: i64 = scan.next();
    writeln!(out, "{}", a + b).unwrap();
}

fn main() {
    let input: Box<dyn BufRead> = if cfg!(debug_assertions) {
        Box::new(BufReader::new(
            File::open("input.txt").expect("input.txt not found"),
        ))
    } else {
        Box::new(BufReader::new(io::stdin()))
    };

    let mut output: Box<dyn Write> = if cfg!(debug_assertions) {
        Box::new(BufWriter::new(
            File::create("output.txt").expect("cannot create output.txt"),
        ))
    } else {
        Box::new(BufWriter::new(io::stdout()))
    };

    let mut scan = Scanner::new(input);

    let tests: usize = scan.next();
    for _ in 0..tests {
        solve(&mut scan, &mut output);
    }
}

struct Scanner<R> {
    reader: R,
    buffer: Vec<String>,
}

impl<R: BufRead> Scanner<R> {
    fn new(reader: R) -> Self {
        Self {
            reader,
            buffer: Vec::new(),
        }
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Parse error");
            }
            let mut input = String::new();
            self.reader.read_line(&mut input).unwrap();
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}
