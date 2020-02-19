import java.io.*;
import java.net.*;


public class Client
{
	
	public static void main(String[] args) throws IOException
	{
		if(args.length != 2)
		{
			
			System.out.println("Usage: java Client <ip address> <port #> ");
			System.exit(0);
		}
		// ip address and port argument processing
		String ip = args[0];
		int port = Integer.parseInt(args[1]);
		
		try{
			Socket socket = new Socket(ip, port);
			BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
			
			
			BufferedReader userInputBR = new BufferedReader(new InputStreamReader(System.in));
			String userInput = userInputBR.readLine();
			
			out.println(userInput);
			
			System.out.println("client: " + userInput);

			System.out.println("server: " + br.readLine());
			
			socket.close();
			
		}
		catch(UnknownHostException e)
		{
			System.err.println("Unknown host " + ip + " -- try using the "
				+ "IP Address instead ");
			System.exit(1);
			
		}
		catch(IOException e)
		{
			System.err.println("Error " + ip);
			System.exit(1);
		}
		
		
		
		
	}
	
}
