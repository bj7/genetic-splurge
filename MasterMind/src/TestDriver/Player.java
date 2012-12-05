package TestDriver;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Player {
	public Socket _socket;
	public BufferedReader in;
	public PrintWriter out;
	
	public int _numPegs;
	public String[] _colorSpace;
	
	public final static String IP = "192.168.1.9"; //this should be the IP of the tournament
	public final static int DEFAULTPORT = 4444;  //this should be the port of the tournament

	public Player(int port) {
		//open the various streams
		try {
			_socket = new Socket(IP, port);
			in = new BufferedReader(new InputStreamReader(_socket.getInputStream()));
			out = new PrintWriter(_socket.getOutputStream());
		} catch (UnknownHostException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		//read the basic info
		readProblemDescription();

		//start writing guesses and getting back results
		String response = null;
		while(response == null || Integer.parseInt(response.split(",")[0]) != _numPegs) {
			sendGuess();
			response = receiveResponse();
			System.out.println(response);
		}
	}
	
	//parse the numPegs and set of colors for guessing
	public void readProblemDescription() {
		String description;
		try {
			description = in.readLine();
			while(description == null)
				description = in.readLine();
			String[] split1 = description.split(";");
			_numPegs = Integer.parseInt(split1[0]);
			_colorSpace = split1[1].split(",");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
		

	//make a random guess
	public void sendGuess() {
		out.println((new Generator(_numPegs, _colorSpace)).generate());
		out.flush(); //REALLY IMPORTANT TO FLUSH
	}

	//parse a response (I don't actually do any parsing here, you need to do that)
	public String receiveResponse() {
		String response;
		try {
			response = in.readLine();
			while(response == null)
				response = in.readLine();
			return response;
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}

	@SuppressWarnings("unused")
	public static void main(String[] args) {
		Player player = new Player(Player.DEFAULTPORT);
	}
}