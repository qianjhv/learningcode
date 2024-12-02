fn main() {
    let width1 = 30;
    let height1 = 50;

    println!(
        "The area of the rectangle is {} square pixels.",
        area(width1, height1)
    );

    let rect1 = (30, 50);
    println!("The area of the rectangle is {} square pixels.", area_dimensions(rect1));

    let rect2 = Rectangle {
        width: 30,
        height: 50
    };

    println!("The area of the rectangle is {} square pixels.", area_rect(&rect2));
    

    println!("The area of the rectangle is {} square pixels.", rect2.area());
}

// normal
fn area(width: u32, height: u32) -> u32 {
    width * height
}

// use tuple
fn area_dimensions(dimensions: (u32, u32)) -> u32 {
    dimensions.0 * dimensions.1
}

// use struct
struct Rectangle {
    width: u32,
    height: u32,
}

fn area_rect(rectangle: &Rectangle) -> u32 {
    rectangle.width * rectangle.height
}

// method syntax
impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

