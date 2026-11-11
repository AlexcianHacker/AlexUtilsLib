// Hconvrs Version For Compatibility With Older Rust Versions 

use std::fs;
use std::env; 
use std::io::{BufRead, Write}; 


/* 
struct acResult { 
    rcd: i64, rstr: Option<String>, 
} 

impl std::process::Termination for acResult { 
    fn outRep(self) -> std::process::ExitCode {} 
}
*/ 


fn convH(inS: String) -> std::io::Result<(u8, String)> { 
    let mut pres: String = String::new(); 
    for chr in inS.chars() { // .chars() For Iterating Over String 
        pres += format!("{:#X} ", chr as u8).as_str(); 
        print!("{:#X} ", chr as u8); 
    } 
    println!(); 
    return Ok((0, pres)); 
} 


// Old: fn main -> std::io::Result<(i64, Option<String>)> 
// Old 2: fn main() -> std::io::Result<std::process::ExitCode> {
fn main() -> std::io::Result<()> { 
    let args: Vec<String> = env::args().collect();
    if args.len() > 1 && args[1] =="s" { 
        let mut inStr: String = String::new(); 
        print!("Enter String To Convert To Hex Here: "); 
        std::io::stdout().flush()?; // Ensure stdout Gets Printed First 
        std::io::stdin().read_line(&mut inStr)?; 
        // let Ok((rc, _rs)) = convH(inStr.trim().to_string()) else { return Err(std::io::Error::other("Failure To Process String From Stdin Into Hex. ")); }; 
        let (rc, _rs) = convH(inStr.trim().to_string())?; 
        if rc != 0 { 
            return Err(std::io::Error::new(std::io::ErrorKind::Other, "Encountered Problems While Processing String From Stdin. \n")); 
        } 
        return Ok(()); 
        // return Ok(std::process::ExitCode::from(rc)); 
        // return Ok((rc as i64, Some(rs))); 
    } 
    let mut inFile: String = String::new(); 
    print!("Enter File Name To Convert To Hex Here: "); 
    std::io::stdout().flush()?; 
    std::io::stdin().read_line(&mut inFile)?; 
    println!("{} \n", inFile); 
    let file = fs::File::open(inFile.trim())?; // Trim To Remove Trailing Chars 
    let mut code: u8 = 0; 
    for line in std::io::BufReader::new(file).lines() { 
        let lin = line?; 
        code += convH(lin)?.0; // Old: "as i64" 
        // ((code, _)) = convH(lin)?; 
    } 
    // fs::write("g.txt", "f* ")?;
    //let text: String =fs::read_to_string(
    // for i in args { println!("{} \n", i); }
    if code != 0 {return Err(std::io::Error::new(std::io::ErrorKind::Other, "Encountered Problems While Processing File. \n")); } 
    return Ok(()); 
    // return Ok(std::process::ExitCode::from(code)); 
    // Ok((code, None)) 
}
