#[derive(Debug)]
enum Number1 {
    Zero = 0,
    One,
    Two,
}

fn main() {
    let a = Number1::Zero;
    print_suit(a);
}

fn print_suit(card: Number1) {
    println!("{:?}",card);
}

