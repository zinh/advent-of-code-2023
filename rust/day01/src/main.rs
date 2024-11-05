pub mod p1;
pub mod p2;

use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        panic!("Require file path");
    }
    let file_path = &args[1];
    let content = fs::read_to_string(file_path).expect("Should have been able to read the file");
    let v: Vec<&str> = content.split('\n').collect();
    let r: u32 = v.iter().map(|line| p1::get_number(p2::convert_chars_to_digit(line))).sum();
    println!("{}", r)
}
