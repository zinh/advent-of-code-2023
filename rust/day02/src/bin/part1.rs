use std::{env, fs};

use day02::{parse_game, valid_game };

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        panic!("Require file path");
    }
    let file_path = &args[1];
    let content = fs::read_to_string(file_path).expect("Should have been able to read the file");
    let v: i32 = content
        .trim()
        .split('\n')
        .map(|item| parse_game(item))
        .filter(|game| valid_game(&game))
        .map(|game| game.id)
        .sum();
    println!("{:?}", v);
}
