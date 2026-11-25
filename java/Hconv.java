import java.io.File; 
// import java.io.FileWriter; 
// import java.io.IOException; 
import java.io.FileNotFoundException; 
import java.util.Scanner; 
// import java.nio.file.attribute.PosixFilePermissions; 
// import java.nio.file.Files; 
// import java.nio.file.Paths; 
// import java.net.URI; 


final class Result { 
	public final short rcode; 
	public final char[] text; 
	public Result(final short rc, final char[] istr) { 
		this.rcode=rc; this.text=istr; return; 
	} 
}  


class Hconv {
	public static Result convH(final char[] txt) { 
		String rStr = new String(); 
		for (short i=0;i<txt.length;++i) { 
			rStr += String.format("0x%X ", (short) txt[i]); 
		} 
		System.err.println(rStr); 
		return new Result((short) 0, rStr.toCharArray()); 
} 	
		public static void main(String[] args) { 
		if (args.length>0 && args[0].equals("s")) { 
			System.err.print("Enter String To Convert To Hex Here: "); 
			final Scanner input = new Scanner(System.in); 
			final char[] inStr = input.nextLine().toCharArray(); 
			input.close(); 
			convH(inStr); 
			return ; 
		}  
		System.err.print("Enter File Name To Convert To Hex Here: "); 
		final Scanner input = new Scanner(System.in); 
		final File file = new File(input.nextLine()); 
		input.close(); 
		try { 
			final Scanner reader = new Scanner(file);  
				// final FileWriter wrfile = new FileWriter("temp_"+args[0], true);  
			System.err.println(); 
			while (reader.hasNextLine()) {  
				convH(reader.nextLine().toCharArray());  
			} 
			/* catch (IOException err) { 
				System.err.println("Error Writing File; " + err.getMessage()); 
			} */  
		} 
		catch (FileNotFoundException e) { 
			System.err.println("Error, File Not Found; " + e.getMessage()); 
		} 
		return ; 
	} 
} 
