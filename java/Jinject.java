import java.io.File; 
import java.io.FileWriter; 
import java.io.IOException; 
import java.io.FileNotFoundException; 
import java.util.Scanner; 
// import java.nio.file.attribute.PosixFilePermissions; 
// import java.nio.file.Files; 
// import java.nio.file.Paths; 
// import java.net.URI; 


class Jinject { 
    public static void main(String[] args) { 
        if (args.length==0 || (args.length<3 && args.length>1)) { 
            System.err.println("Invalid, Not Enough Arguments; Run With --help For More Info "); 
            return ; 
        } 
        if (args.length==1 || args[0].equals("--help")) { 
            System.err.println("JINJECT \n\nUsage: jinject [File] [Line Number] [Content] "); 
            return ; 
        }  
        final File file = new File(args[0]); 
        try { 
            final Scanner reader = new Scanner(file);  
            try { 
            final FileWriter wrfile = new FileWriter("temp_"+args[0], true);  
            int i=0; 
            while (reader.hasNextLine()) { ++i;  
                if (Integer.parseInt(args[1])==i) { 
                    String cat = new String(); 
                    for (short j=2;j<args.length;++j) { 
                        cat += args[j];  
                    } 
                    wrfile.write(cat + "\n"); 
                    reader.nextLine(); 
                } 
                else { 
                    wrfile.write(reader.nextLine() + "\n"); 
                } 
            } 
            wrfile.close(); 
            final File nfile=new File("temp_"+args[0]); 
            nfile.renameTo(file); 
            } 
            catch (IOException err) { 
                System.err.println("Error Writing File; " + err.getMessage()); 
            } 
            reader.close(); 
        } 
        catch (FileNotFoundException e) { 
            System.err.println("Error, File Not Found; " + e.getMessage()); 
        } 
        return ; 
    } 
} 
