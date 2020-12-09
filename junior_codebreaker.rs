use std::io;
use std::io::Write;

fn main() {
    println!("Welcome to the junior code breaker!");
    print!("Please enter a phrase: ");
    io::stdout().flush().unwrap();

    let mut guess = String::new();
    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");
    
    // Takes care of newline
    guess.pop();

    println!("You said: {}",guess);
}
