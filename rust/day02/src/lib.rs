#[derive(Debug)]
pub struct Game {
    pub id: i32,
    sets: Vec<GameSet>,
}

#[derive(Debug)]
struct GameSet {
    blue: i32,
    green: i32,
    red: i32,
}

fn parse_game_id(line: &str) -> i32 {
    let result: Vec<&str> = line.split(' ').collect();
    match result[..] {
        [_first, id] => match id.trim().parse() {
            Ok(num) => return num,
            Err(_) => panic!("Failed!"),
        },
        _ => panic!("Failed!"),
    }
}

fn parse_sets(line: &str) -> Vec<GameSet> {
    return line.split(';').map(|set| parse_set(set)).collect();
}

fn parse_set(line: &str) -> GameSet {
    let mut result = GameSet {
        blue: 0,
        green: 0,
        red: 0,
    };
    for item in line.split(',') {
        let vals: Vec<&str> = item.trim().split(' ').map(|i| i.trim()).collect();
        match vals[..] {
            [count, "blue"] => result.blue = count.trim().parse().expect("Expect a number"),
            [count, "green"] => result.green = count.trim().parse().expect("Expect a number"),
            [count, "red"] => result.red = count.trim().parse().expect("Expect a number"),
            _ => panic!("Unknown format: {:?}", vals),
        }
    }
    return result;
}

pub fn parse_game(line: &str) -> Game {
    let result: Vec<&str> = line.split(':').collect();
    match result[..] {
        [first, last] => {
            return Game {
                id: parse_game_id(first),
                sets: parse_sets(last),
            }
        }
        _ => panic!("Error!"),
    }
}

pub fn power_set(game: Game) -> i32 {
    let mut red = 0;
    let mut blue = 0;
    let mut green = 0;
    for set in &game.sets {
        if set.green > green {
            green = set.green
        }
        if set.red > red {
            red = set.red
        }
        if set.blue > blue {
            blue = set.blue
        }
    }
    return red * blue * green;
}

pub fn valid_game(game: &Game) -> bool {
    for set in &game.sets {
        if set.blue > 14 || set.green > 13 || set.red > 12 {
            return false;
        }
    }
    return true;
}
