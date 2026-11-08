use std::fs;
use std::env;
use std::convert::TryInto; 


fn main() -> std::io::Result<()> {
    let args: Vec<String> = env::args().collect();
    if args.len() == 2 && args[1] == "--help" { 
        println!("RINJECT \n\nUsage: rinject [File] [Line Number] [Content] \n"); 
        return Ok(()) 
    } 
    else if args.len() < 4 { 
        println!("Invalid, Not Enough Arguments; Run With --help For More Info. \n"); 
        return Ok(()) 
    }
    let args1: &String = &args[1];
    let bruhbind = fs::read_to_string(&args1)?; 
    let mut contents: Vec<&str> = bruhbind.lines().collect(); 
    // fs::write("temp_" + args[1], contents);
    let mut i: usize = 3; 
    let mut nstr: String = String::new(); 
    while i < args.len().try_into().unwrap() { 
        nstr += args[i].as_str(); 
        i+=1; 
    }
    contents[args[2].parse::<usize>().unwrap() - 1] = nstr.as_str();
    let mut nl: String = String::new(); 
    if contents[contents.len() - 1].contains("\n") { nl = "\n".to_string(); } 
    fs::write(&args1, contents.join("\n")+&nl)?; 
    /* let mut i: u64 = 0; 
    while i < contents.len() { 
        if i == args[2].parse()? { } 
    */ 
    if contents.len() < 1 && args[2].parse::<usize>().unwrap() > 0 { // Sexy Short Circuiting 
        contents.push(" \n{}"); 
        contents.push(&nstr); 
        fs::write(&args1, contents.join("\n"))?; 
    } 
    // fs::write("g.txt", "f* ahh ");
    //let text: String =fs::read_to_string(
    // for j in args { println!("{} \n", j); }
    Ok(()) 
}  
