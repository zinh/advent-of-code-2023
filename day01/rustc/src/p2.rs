pub fn convert_chars_to_digit(s: &str) -> String {
    // print!("{}:", s);
    let keys = vec![
        (String::from("sevenine"), String::from("79")),
        (String::from("nineight"), String::from("98")),
        (String::from("oneight"), String::from("18")),
        (String::from("fiveight"), String::from("58")),
        (String::from("eightwo"), String::from("82")),
        (String::from("eighthree"), String::from("83")),
        (String::from("threeight"), String::from("38")),
        (String::from("twone"), String::from("21")),
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
    // println!("{}", result);
    return result;
}

