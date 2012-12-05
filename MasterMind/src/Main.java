/**
 * This program implements a mastermind AI that uses genetic algorithms.
 */
import java.util.Random;
import TestDriver.*;
import java.net.*;
import java.io.*;
/**
 * @author joshbernitt
 *
 */
public class Main {

	private static int numColors;
	private static int numPegs;
	private static BufferedReader socIn;
	private static PrintWriter socOut;
	private static Socket connection;
	private static String[] colorList;
	private static Organism bestIndividual;
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//defaulting
		numPegs = 0;
		numColors = 0;
		
		//getting socket to use
		System.out.println("Please enter socket: ");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = null;
		try{
			input = br.readLine();
		}
		catch(IOException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		System.out.println("Socket entered was: " + input);
		int socket = Integer.parseInt(input); //turning the string into an int for the socket number
			
		//getting IP
		System.out.println("Please enter IP address of host: ");
		try{
			input = br.readLine();
		}
		catch(IOException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		String ip = input;
		
		//setting up communications 
		socket( ip, socket);
		
		//getting problem description
		getProblemDescription();
		
		bestIndividual = new Organism(numPegs); //setting up default for the place holder of the current best individual
		
		//initialize population
		int initSize = 200;
		Organism[] initial_population = new Organism[initSize]; //some arbitrary size
		for(int i =0; i < initSize; i++){
			Organism new_creature = new Organism(numPegs);
			initial_population[i] = new_creature;
		}
		
		setBestIndividual();
		geneticAlgo(initial_population);
		
		//start writing guesses
		//simpleGuess();
		
	}//end method
	
	private static void setBestIndividual(){
		String[] colorsUsed = new String[numPegs]; //keeping track of what colors are used in the code
		int count = 0;
		
		//pre-guess work to narrow down colors used
		for(int i = 0; i < numColors; i++){
			String[] guess = new String[numPegs]; //create a new guess for every color
			String response;
			String[] received = {"0","0"}; //initialized to no red pegs and no white pegs 
			
			for(int j = 0; j < numPegs; j++)
				guess[j] = colorList[i]; //fill up our guess to be monochromatic
				
			sendGuess(guess);
			response = receiveResponse();
			received = response.split(",");
			
			int numReceived = Integer.parseInt(received[0]); //making a counter for the number of reds for each color
			while(numReceived > 0){ //while there are still more reds for this color
				colorsUsed[count] = guess[0]; //set the colors used to the color
				count++; //increase the counter for the array
				numReceived--; //decrease the amount of reds we have left for this color
			}
		}
		
		//start legit guesses
		String[] guess = new String[numPegs];
		for(int i = 0; i < numPegs; i++){ //initial setup to fill our guess with only colors used
			bestIndividual.setPeg(i, colorsUsed[i]);
		}
		
	}
	
	/**
	 * Simple method to perform simple guesses. We iterate through a guess trying every color at each position until
	 * we have found all the colors in their correct place. Note: this will fail if the first guess contains a red peg.
	 */
	private static void simpleGuess(){
		String[] colorsUsed = new String[numPegs]; //keeping track of what colors are used in the code
		int count = 0;
		
		//pre-guess work to narrow down colors used
		for(int i = 0; i < numColors; i++){
			String[] guess = new String[numPegs]; //create a new guess for every color
			String response;
			String[] received = {"0","0"}; //initialized to no red pegs and no white pegs 
			
			for(int j = 0; j < numPegs; j++)
				guess[j] = colorList[i]; //fill up our guess to be monochromatic
				
			sendGuess(guess);
			response = receiveResponse();
			received = response.split(",");
			
			int numReceived = Integer.parseInt(received[0]); //making a counter for the number of reds for each color
			while(numReceived > 0){ //while there are still more reds for this color
				colorsUsed[count] = guess[0]; //set the colors used to the color
				count++; //increase the counter for the array
				numReceived--; //decrease the amount of reds we have left for this color
			}
		}
		
		//start legit guesses
		String[] guess = new String[numPegs];
		String response;
		String[] received = {"0","0"}; //initialized to no red pegs and no white pegs 
		for(int i = 0; i < numPegs; i++){ //initial setup to fill our guess with only colors used
			guess[i] = colorsUsed[i];
		}
		
		//begin sending and receiving guesses and responses
		int i = 0;
		while(Integer.parseInt(received[0]) != numPegs){ //while we do not have a goal
			sendGuess(guess);
			response = receiveResponse();
			received = response.split(",");
			
			if(i < numPegs-1 && Integer.parseInt(received[0]) != 0){ //basically marching across and exchanging each color with the one ahead of it
				String temp = guess[i]; //place holder
				guess[i] = guess[i+1]; //make the current peg be the next one   Red,green,yellow...
				guess[i+1] = temp; //march the previous peg ahead by one        green,Red,yellow...
				i++;
			}
			else //reset so we touch each color
				i = 0;
			
			//if for some reason our previous attempt made it so we had no pegs in the proper location
			if(Integer.parseInt(received[0]) == 0){
				for(int j = 0; j < numPegs; j++){ //march through from peg to peg and try each color until it is right
					for(int k = 0; k < count; k++){
						guess[j] = colorsUsed[k];
						
						sendGuess(guess);
						response = receiveResponse();
						received = response.split(",");
						
						if(Integer.parseInt(received[0]) > j) //if we found a color in the correct location
							k = count; //stop changing the color there
					}
				}
			}
			
		}
		
		//Goal test
		if(Integer.parseInt(received[0]) == numPegs){ //testing if #of reds equals #of pegs thus indicating goal
			//Alerting us and printing out the goal
			System.out.println("Goal!");
		}
	}//end method
	
	/**
	 * Method to receive the Response from the server. Returns the string of the response or null if error
	 * @return response
	 */
	private static String receiveResponse(){
		String response; //string to return
		
		try{
			response = socIn.readLine();
			while(response == null)
				response = socIn.readLine();
			System.out.println("Response: " + response);
			return response;
		}
		catch(IOException e){
			System.out.println("cannot receive response from server");
			e.printStackTrace();
			return null;
		}
	}//end method
	
	/**
	 * Method to send our guess to the server. Takes a parameter of a String array holding our guess.
	 * @param guess
	 */
	private static void sendGuess(String[] guess){
		StringBuffer sb =  new StringBuffer(); //create string buffer so we can parse output
		for(int i = 0; i < numPegs; i++){
			sb.append(guess[i]); //appending the colors to form a list
			if( i < numPegs-1) //as long as we aren't the last entry, comma separate
				sb.append(",");
		}
		socOut.println(sb);
		socOut.flush();
		System.out.println("Guess: " + sb);
	}//end method
	
	/**
	 * Method to initialize communication to server. Takes in the ip and the socket to use.
	 * @param ip
	 * @param socket
	 */
	private static void socket(String ip, int socket){
		//setting up connection
		System.out.println("Connecting to " + ip + " on port " + socket);
		try{
			connection = new Socket(ip, socket);
			socIn = new BufferedReader(new InputStreamReader(connection.getInputStream())); //reading in data from host
			socOut = new PrintWriter(connection.getOutputStream()); //printing data back to host
		}
		catch(UnknownHostException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		catch(IOException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}//end method
	
	/**
	 * Method to get problem description for use
	 */
	private static void getProblemDescription(){
		String description;
		try{
			description = socIn.readLine(); //reading in from the socket
			while(description == null)
				description = socIn.readLine();
			String[] split1 = description.split(";"); //break into an array based on 4; black, white, blue, ..., n with the number being the number of pegs or codeSize
			numPegs = Integer.parseInt(split1[0]); 
			colorList = split1[1].split(","); //break into a list of each individual color
			numColors = colorList.length;
			System.out.println("Number of pegs = "+numPegs);
			System.out.println("Color List: ");
			for(int i = 0; i < numColors; i++)
				System.out.println(colorList[i]);
		}
		catch(IOException e){
			e.printStackTrace();
		}
	}//end method
	
	/**
	 * Method initializes the genome of each creature with a random
	 * number between 0 and the number of colors 
	 * @param creature
	 * @return none
	 */
	private static void genomeInit(Organism creature){
		Random generator = new Random();
		
		for (int i = 0; i < numPegs; i++){
			creature.setPeg(i, generator.nextInt(numColors)); //setting each peg to some random number that corresponds to a color
		}
	}//end method
	
	/**
	 * Method implements the genetic algorithm
	 * @param none
	 * @return none
	 */
	private static void geneticAlgo(Organism[] population){
		double keepers = 0.4;
		while(!hasGoal(population)){ //testing on whether the population has any goal in it
			int fitIndividuals = 0; //counter for fit individuals
			Organism[] fitPopulation = new Organism[population.length]; //setting up a population of only fit individuals
			
			for(int i = 0; i < population.length; i++){ //determining fitness of each individual in the population
				fitness(population[i]);
				if(population[i].getFitness() >= keepers){ //if the fitness >= the current desired number to indicate if we keep it
					fitIndividuals++;
					fitPopulation[i] = population[i]; //places all fit individuals into the fitPopulation
				}
			}
			
			population = new Organism[fitIndividuals]; //redefine population to hold the fit individuals
			for(int i = 0; i < fitIndividuals; i++)
				population[i] = fitPopulation[i]; //placing the fit individuals into the population
			
			Organism[] new_population = new Organism[population.length/2]; //setting up the new population to hold the children
			
			for(int i = 0; i < population.length; i++){
				Organism x;
				Organism y;
				Organism offspring;
			
				x = randomSelect(population);
				y = randomSelect(population);
				offspring = reproduce(x, y);
			
				//random Mutation
				Random mutationChance = new Random();
				if(mutationChance.nextInt(population.length) == 1) //small percentage of mutation: 1/sizeOf(population)
					offspring = mutate(offspring);
			
				new_population[i] = offspring; //place the offspring into the empty set of the new population
			}
			//redefine population
			population = new Organism[new_population.length]; //redefine population
			for(int i = 0; i < new_population.length; i++) //put the children into the old population
				population[i] = new_population[i];
			
			keepers += 0.1; //for each iteration of a new population, increase the rank at which we will accept a fitness
		}
		
	}//end method
	
	/**
	 * Method to make a random mutation in the creature. Takes in one creature to mutate.
	 * @param creature
	 * @return Organism
	 */
	private static Organism mutate(Organism creature){
		Random generator = new Random();
		int mutationLoc = generator.nextInt(creature.getSize()); //select a random mutation location based on the size of the genome
		int mutationType = generator.nextInt(numColors); //select a random color to mutate to based on the number of colors
		
		creature.setPeg(mutationLoc, mutationType); //set the mutation
		return creature;
	}//end method
	
	/**
	 * Method to determine if the current population has a goal in it. Takes in a population and searches through it.
	 * Returns true if a goal creature is found or false otherwise.
	 * @param population
	 * @return boolean
	 */
	private static boolean hasGoal(Organism[] population){
		for(int i = 0; i < population.length; i++){
			if(population[i].getFitness() == 1)
				return true;
		}
		return false;
	}//end method
	
	/**
	 * Method to randomly select an organism from the population. Takes in a list of the population and returns
	 * the selected individual.
	 * @param population
	 * @return organism
	 */
	private static Organism randomSelect(Organism[] population){
		Random select = new Random();
		int randomi = select.nextInt(population.length); //setting up my random selector based on the population size
		
		Organism individual = new Organism();
		individual = population[randomi]; //choose some random individual
		
		return individual;
	}
	
	/**
	 * Method to reproduce the two organisms giving one. Takes in two parents and returns a child.
	 * @param x
	 * @param y
	 * @return organism
	 */
	private static Organism reproduce(Organism x, Organism y){
		Random generator = new Random();
		int index = generator.nextInt(numPegs); //get some random index based on the number of pegs
		
		for(int i = index; i < numPegs; i++)
			x.setPeg(i, y.getPeg(i)); //start the cross over setting values > the random index to be the values from y
		
		return x;
	}
	
	/**
	 * Method to determine the fitness of each organism based on how close it appears to the bestIndividual
	 * @param creature
	 * @return fitness
	 */
	private static double fitness(Organism individual){
		double fitness = 0;
		
		//compare with bestIndividual
		for(int i = 0; i < individual.getSize(); i++){
			if(individual.getPeg(i) == bestIndividual.getPeg(i))
				fitness += 0.5; //if the individual had a peg in the same place as our current best guess
			else if(contains(individual.getPeg(i)) && individual.getPeg(i) != bestIndividual.getPeg(i)) //as long as the locations are not the same
				fitness += 0.25; //if the individual contains some peg that is in the bestIndividual
		}
		
		fitness = fitness/individual.getSize(); //take whatever total we have and divide by the number of pegs
		
		if(fitness <= 0.4) //if the fitness is really sucky, just set it to zero because we will always ignore this individual
			fitness = 0;
		
		return fitness;
	}//end method
	
	/**
	 * Method to test if the peg passed in is contained in the bestIndividual's genome.
	 * @param peg
	 * @return boolean
	 */
	private static boolean contains(int peg){
		for(int i = 0; i < bestIndividual.getSize(); i++){
			if(peg == bestIndividual.getPeg(i))
				return true;
		}
		return false;
	}//end method
	
	/**
	 * Method to convert from the int[] type of genome in the Organism to the String[] of colors. Takes in an individual.
	 * @param individual
	 * @return String[]
	 */
	private static String[] convert(Organism individual){
		String[] colors = new String[individual.getSize()];
		
		for(int i = 0; i < individual.getSize(); i++){
			colors[i] = colorList[individual.getPeg(i)];
		}
		return colors;
	}//end class

}
