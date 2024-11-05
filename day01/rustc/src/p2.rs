pub fn convert_chars_to_digit(s: &str) -> String {
    let keys = vec![
        (String::from("one"), String::from("1")),
        (String::from("two"), String::from("2")),
        (String::from("three"), String::from("3")),
        (String::from("four"), String::from("4")),
        (String::from("five"), String::from("5")),
        (String::from("six"), String::from("6")),
        (String::from("seven"), String::from("7")),
        (String::from("eight"), String::from("8")),
        (String::from("nine"), String::from("9")),
    ];
    let mut result: String = String::from(s);
    for (k, v) in keys.iter() {
        result = result.replace(k, v);
    }
    println!("{}", result);
    return result;
}

