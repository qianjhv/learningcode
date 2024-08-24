fn main() {
	println!("{}", fahrenheit_to_celsius(1.0));
	println!("{}", fibonacci(11));
	the_twelve_days_of_christmas();
}

// 3-1
fn fahrenheit_to_celsius(fah: f32) -> f32 {
	(fah - 32.0) / 1.8
}

// 3-2
//[1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...]
// zero is not the first term, but the zeroth term - f(0) 
fn fibonacci(n: u8) -> u64 {
	 let mut a: u64 = 0;
    let mut b: u64 = 1;

    for _ in 0..n {
        let temp = a;
        a = b;
        b = temp + b;
    }

    a	
}

// 3-3 
fn the_twelve_days_of_christmas() {
	let gifts = [
        "a Partridge in a Pear Tree",
        "two Turtle Doves",
        "three French Hens",
        "four Calling Birds",
        "five Gold Rings",
        "six Geese a Laying",
        "seven Swans a Swimming",
        "eight Maids a Milking",
        "nine Ladies Dancing",
        "ten Lords a Leaping",
        "eleven Pipers Piping",
        "twelve Drummers Drumming",
    ];

    let days = [
        "first", "second", "third", "fourth", "fifth", "sixth", "seventh",
        "eighth", "ninth", "tenth", "eleventh", "twelfth",
    ];

    for day in 0..12 {
        println!(
            "On the {} day of Christmas,\nmy true love gave to me:",
            days[day]
        );

        for gift_index in (0..=day).rev() {
            if day > 0 && gift_index == 0 {
                print!("and ");
            }
            println!("{}", gifts[gift_index]);
        }

        println!(); // Print a newline for separation between days
    }
}
