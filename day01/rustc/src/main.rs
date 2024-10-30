use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        panic!("Require file path");
    }
    let file_path = &args[1];
    println!("Read from: {}", file_path);
    let content = fs::read_to_string(file_path).expect("Should have been able to read the file");
    let _v: Vec<&str> = content.split('\n').collect();
    println!("{}", content);
}
