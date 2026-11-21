import java.io.File; 
import java.io.FileWriter; 
// import java.io.FileNotFoundException; 
// import java.util.Scanner; 
import java.io.IOException; 
// import java.nio.file.attribute.PosixFilePermissions; 
// import java.nio.file.Files; 
// import java.nio.file.Paths; 
// import java.net.URI; 


class Canonize { 
    public static void main(String[] args) { 
        if (args.length < 2) { 
            System.err.println("No Arguments Detected"); 
            return ; 
        }  
        final char[] ln = ("/usr/local/bin/" + args[0]).toCharArray(); 
        try { 
            final FileWriter clear=new FileWriter(String.valueOf(ln), false); // Open File As Non-Appending First To Clear It  
            clear.close(); 
            final FileWriter file = new FileWriter(String.valueOf(ln), true); 
            file.write("#!/bin/sh\n"); 
            for (short i=1;i<args.length;++i) { 
                file.write(args[i] + " "); 
            } 
            file.write("\"$@\""); 
            file.close(); 
        } 
        catch (IOException e) { 
            System.err.println("Error Writing File; " + e.getMessage()); 
        } 
        final File f = new File(String.valueOf(ln)); 
        f.setReadable(true, false); // boolean readable, boolean ownerOnly 
        f.setWritable(true, true); 
        f.setExecutable(true, false); 
        // Files.setPosixFilePermissions(Paths.get(URI.resolve(String.valueOf(ln))), PosixFilePermissions.fromString("rwxr-xr-x")); 
        return ; 
    } 
} 
