use std::fs;
use std::env; 
use std::os::unix::fs::PermissionsExt; 

fn main() -> std::io::Result<()> {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 { 
        println!("Not Enough Arguments Detected \n"); 
    } 
    else if args.len() >= 3 { 
        let path: String = "/usr/local/bin/".to_owned() + &args[1]; 
        let mut epath: String = String::new(); 
        let mut i: usize = 2;
        epath+="#!/bin/sh\n"; 
        while i < args.len() { 
            epath+=&args[i]; 
            // fs::write(&path, <String as Clone>::clone(&args[i]));
            i+=1;
        }
        fs::write(&path, epath+" \"$@\"")?;
        let mut perms = fs::metadata(&path)?.permissions(); 
        perms.set_mode(0o755); 
        fs::set_permissions(path, perms)?;
        // fs::write("g.txt", "f* ahh ");
        //let text: String =fs::read_to_string(
        // for j in args { println!("{} \n", j); }
    } 
    Ok(()) 
}  
