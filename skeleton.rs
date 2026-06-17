use std::fs::File;
use std::io::{self, Read, Write, BufWriter};

fn solve<W: Write>(scan: &mut Scanner, out: &mut W) {
}

fn main() {
    let mut input_str = String::new();
    if cfg!(debug_assertions) {
        File::open("input.txt")
            .expect("input.txt not found")
            .read_to_string(&mut input_str)
            .unwrap();
    } else {
        io::stdin().lock().read_to_string(&mut input_str).unwrap();
    }

    let mut scan = Scanner::new(&input_str);

    if cfg!(debug_assertions) {
        let mut out = BufWriter::new(File::create("output.txt").expect("cannot create output.txt"));
        run_tests(&mut scan, &mut out);
    } else {
        let mut out = BufWriter::new(io::stdout().lock());
        run_tests(&mut scan, &mut out);
    }
}

fn run_tests<W: Write>(scan: &mut Scanner, out: &mut W) {
    let tests: usize = scan.next();
    for _ in 0..tests {  solve(scan, out); }
}

struct Scanner<'a> { 
    iter: std::str::SplitAsciiWhitespace<'a> 
}

impl<'a> Scanner<'a> {
    fn new(s: &'a str) -> Self { Self { iter: s.split_ascii_whitespace() } }
    
    fn next<T: std::str::FromStr>(&mut self) -> T {
        self.iter.next()
            .expect("EOF")
            .parse()
            .ok()
            .expect("Parse Error")
    }
}
