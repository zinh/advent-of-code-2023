pub fn get_number(s: String) -> u32 {
    let digits: Vec<u32> = s
        .chars()
        .filter(|&c| c >= '0' && c <= '9')
        .map(|c| c.to_digit(10).unwrap())
        .collect();
    // for d in &digits {
    //     print!("{}", d);
    // }
    // println!("");
    match digits.first() {
        Some(first) => match digits.last() {
            Some(last) => 10 * first + last,
            None => return *first,
        },
        None => return 0,
    }
}
