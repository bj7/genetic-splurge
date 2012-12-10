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
	private static Organism[] priorGuesses;
	private static int priorGuessCount;
	
	  
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
		
		//initialize population to empty
		int initSize = 500;
		Organism[] initial_population = new Organism[initSize]; //some arbitrary size
		for(int i =0; i < initSize; i++){
			Organism new_creature = new Organism(numPegs);
			initial_population[i] = new_creature;
		}
		
		priorGuessCount = 0;
		priorGuesses = new Organism[initial_population.length];
		bestIndividual = new Organism(numPegs); //setting up default for the place holder of the current best individual
		setBestIndividual();
		
		//seed population
		for(int i = 0; i < initial_population.length; i++)
			eliteGenomeInit(initial_population[i]); //TODO
		
		geneticAlgo(initial_population);
		
		//start writing guesses
		//simpleGuess();
		
	}//end method
	
	/**
	 * Method to set the bestIndividual to hold only colors used in this round.
	 */
	private static void setBestIndividual(){
		String[] colorsUsed = new String[numPegs]; //keeping track of what colors are used in the code
		int count = 0;
		String response;
		String[] received = {"0","0"}; //initialized to no red pegs and no white pegs 
		
		//pre-guess work to narrow down colors used
		for(int i = 0; i < numColors; i++){
			String[] guess = new String[numPegs]; //create a new guess for every color
			
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
		
		//determine fitness of bestIndividual using same fitness function as all others
		sendGuess(colorsUsed);
		response = receiveResponse();
		received = response.split(",");
		double numReds = Integer.parseInt(received[0]);
		double numWhites = Integer.parseInt(received[1]);
		double fitness = numReds/numPegs + (numWhites/(numPegs+1));
		bestIndividual.setFitness(fitness);
		
		bestIndividual.setReds(numReds);
		bestIndividual.setWhites(numWhites);
		
		System.out.println("Fitness of best individual thus far: " + bestIndividual.getFitness());
		
		//fill bestIndividual with the ints that correspond to the colors used
		for(int i = 0; i < numPegs; i++){ //initial setup to fill our guess with only colors used
			bestIndividual.setPeg(i, convertToInt(colorsUsed[i]));
		}

		if(bestIndividual.getReds() == numPegs){
			System.out.println("Goal!");
			System.exit(0);
		}
		
		priorGuesses[priorGuessCount] = bestIndividual;
		priorGuessCount++;
		
	}//end method
	
	/**
	 * Method to convert a color to an int
	 * @param color
	 * @return int
	 */
	private static int convertToInt(String color){
		for(int i = 0; i < colorList.length; i++){
			if(color == colorList[i])
				return i;
		}
		return -1;
	}//end method
	
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
		
		//10% chance that the bestIndividual will be seeded into the population thus creating elites
		int random = generator.nextInt(10);
		if(random == 1){
			eliteGenomeInit(creature);
		}
	}//end method
	
	/**
	 * Method to create only elite random creatures.
	 * @param creature
	 */
	private static void eliteGenomeInit(Organism creature){
		Random generator = new Random();
			
		for(int i = 0; i < numPegs; i++){
				creature.setPeg(i, bestIndividual.getPeg(i));
		}
		//randomly switching the chromosome with another spot in the genome
		int i = 0;
		while(i < numPegs){
			int index = generator.nextInt(numPegs);
			int newIndex = generator.nextInt(numPegs);
			int oldPeg = creature.getPeg(newIndex);
			creature.setPeg(newIndex, creature.getPeg(index));
			creature.setPeg(index, oldPeg);
			i++;
		}
		
	}//end method
	
	/**
	 * Method implements the genetic algorithm
	 * @param none
	 * @return none
	 */
	private static void geneticAlgo(Organism[] population){
		double keepers = bestIndividual.getFitness() - 0.3;
		int numGenerations = 0; 
		int viables = 0; //counting the number of viable guesses each generation has
		int iterations = 0;
		while(true){  
			
			if(iterations >= 100)
				simpleGuess();
			
			//if we have not had a viable guess in 15 generations, kill the current and restart the population
			if(numGenerations - viables >=15){
				//initialize population to empty
				int initSize = 500;
				Organism[] initial_population = new Organism[initSize]; //some arbitrary size
				for(int i =0; i < initSize; i++){
					Organism new_creature = new Organism(numPegs);
					initial_population[i] = new_creature;
				}
				
				//initialize genomes of population
				for(int i = 0; i < initial_population.length; i++)
					eliteGenomeInit(initial_population[i]); //TODO
				
				numGenerations = 0;
				viables = 0;
			}
			//if population ever has a size of 0 restart
			if(population.length == 0){
				//initialize population to empty
				int initSize = 150;
				Organism[] initial_population = new Organism[initSize]; //some arbitrary size
				for(int i =0; i < initSize; i++){
					Organism new_creature = new Organism(numPegs);
					initial_population[i] = new_creature;
				}
				
				//initialize genomes of population
				for(int i = 0; i < initial_population.length; i++)
					eliteGenomeInit(initial_population[i]); //TODO
				
				numGenerations = 0;
				viables = 0;
			}
			
			Organism[] new_population = new Organism[population.length]; //setting up the new population to hold the children
			
			for(int i = 0; i < population.length; i++){
				Organism x;
				Organism y;
				Organism offspring;
			
				x = randomSelect(population);
				y = randomSelect(population);
				//try to ensure no asexual reproduction
				if(x == y)
					y = randomSelect(population);
				offspring = reproduce(x, y);
			
				//random Mutation on 0.03% chance
				Random mutationChance = new Random();
				if(mutationChance.nextInt(30) == 1) //small percentage of mutation: 1/30 = 0.033
					offspring = mutate(offspring);
				
				//random inversion of genome on 0.03% chance
				if(mutationChance.nextInt(30) == 1){
					inversion(offspring);
				}
				
				//if our offspring is the same as something in the population, mutate it
				for(int j = 0; j < population.length; j++){
					if(sameGenome(offspring, population[i]))
						mutate(offspring);
				}
			
				new_population[i] = offspring; //place the offspring into the empty set of the new population
			}
			//redefine population to hold any offspring that have a better fitness
			for(int i = 0; i < new_population.length; i++){
				for(int j = 0; j < population.length; j++){
					if(new_population[i].getFitness() > population[j].getFitness()){
						population[j] = new_population[i];
						i++;
						j = population.length;
					}
				}
			}
			
			//only keep individuals that match our desired fitness level
			int fitcount = 0;
			Organism[] fitPop = new Organism[population.length];
			for(int i = 0; i < population.length; i++){
				if(population[i].getFitness() > keepers){
					fitPop[fitcount] = population[i];
					fitcount++;
				}
			}
			
			//put fit population into normal population
			population = new Organism[fitcount];
			for(int i = 0; i < fitcount; i++)
				population[i] = fitPop[i];
			
			//testing all individuals that have a really high fitness compared to the current bestIndividual
			for(int i = 0; i < population.length; i++){
				if(population[i].getFitness() >= 0.75){
					testNewBestIndividual(population[i]);
					viables++;
				}
			}
			numGenerations++;
			iterations++;
		}
		
	}//end method
	
	/**
	 * Method to invert the genome of the individual
	 * @param individual
	 */
	private static void inversion(Organism individual){

		for(int i = 0; i < numPegs/2; i++){
			individual.setPeg(i, individual.getPeg(numPegs-1-i));
		}
	} //end method
	
	/**
	 * Method to test if the two organisms have the same genome
	 * @param first
	 * @param second
	 * @return boolean
	 */
	private static boolean sameGenome(Organism first, Organism second){
		int counter = 0;
		for(int i = 0; i < numPegs; i++){
			if(first.getPeg(i) == second.getPeg(i))
				counter++;
		}
		if(counter == numPegs)  //if the number of pegs that were the same is equal to the total number of pegs then they are the same
			return true;
		return false;
	} //end method
	
	/**
	 * Method to determine if there exists a better individual to base our fitness' on
	 */
	private static void testNewBestIndividual(Organism potential){
		//test if we've seen this genome before, so we don't repeat and we can save guesses
		for(int i = 0; i < priorGuessCount; i++){
			if(sameGenome(potential, priorGuesses[i])){
				//since we have seen this organism before set it to the previously recorded measures and return
				potential.setFitness(priorGuesses[i].getFitness());
				potential.setReds(priorGuesses[i].getReds());
				potential.setWhites(priorGuesses[i].getWhites());
				return;
			}
		}
		actualFitness(potential);
		
		//test if our potential really was at least as good as our bestIndividual thus far
		if(potential.getFitness() >= bestIndividual.getFitness() && bestIndividual.getReds() <= potential.getReds()){
			bestIndividual = potential;
			System.out.println("New best individual's fitness: " + bestIndividual.getFitness());
		}
			System.out.println("Fitness: " + potential.getFitness());
		
			//if we get too many guesses, just restart
		if(priorGuessCount >= priorGuesses.length)
			priorGuessCount = 0;
		priorGuesses[priorGuessCount] = bestIndividual;
		priorGuessCount++;
		
		//goal test
		if(bestIndividual.getReds() == numPegs){
			System.out.println("Goal!");
			System.exit(0);
		}
		
	} //end method
	
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
	 * Method to randomly select an organism from the population. Takes in a list of the population and returns
	 * the selected individual.
	 * @param population
	 * @return organism
	 */
	private static Organism randomSelect(Organism[] population){
		Random select = new Random();
		int randomi = 0;
		randomi = select.nextInt(population.length); //setting up my random selector based on the population size
		
		Organism individual = new Organism();
		individual = population[randomi]; //choose some random individual
		
		//breading selection based directly on the individuals fitness. Lower fitness means greater chance of new selection
		//if fitness <= 0.5 then 50% chance of new individual being chosen
		if(individual.getFitness() <= 0.5){
			randomi = select.nextInt(4);
			if(randomi == 1 || randomi == 2);
				randomi = select.nextInt(population.length);
			individual = population[randomi];
		}
		//if between 0.5 and 0.6 then a 40% chance of new selection
		if(individual.getFitness() > 0.5 && individual.getFitness() <= 0.6){
			randomi = select.nextInt(10);
			if(randomi == 1 || randomi == 2 || randomi == 3 || randomi == 4);
				randomi = select.nextInt(population.length);
			individual = population[randomi];
		}
		//if between 0.6 and 0.7 then 30% chance
		if(individual.getFitness() > 0.6 && individual.getFitness() <= 0.7){
			randomi = select.nextInt(10);
			if(randomi == 1 || randomi == 2 || randomi == 3);
				randomi = select.nextInt(population.length);
			individual = population[randomi];
		}
		//if between 0.7 and 0.8 then 20% chance
		if(individual.getFitness() > 0.7 && individual.getFitness() <= 0.8){
			randomi = select.nextInt(10);
			if(randomi == 1 || randomi == 2);
				randomi = select.nextInt(population.length);
			individual = population[randomi];
		}
		//if between 0.8 and 1.0 then 10% chance
		if(individual.getFitness() > 0.8 && individual.getFitness() <= 1){
			randomi = select.nextInt(10);
			if(randomi == 1);
				randomi = select.nextInt(population.length);
			individual = population[randomi];
		}
		
		//the leader of the population always has a better chance of reproducing, in this case 25%
		randomi = select.nextInt(4);
		if(randomi == 1)
			individual = bestIndividual;
		
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
		Organism offspring = new Organism(numPegs);
		
		//setting the offspring to hold what was in x
		for(int i = 0; i < x.getSize(); i++)
			offspring.setPeg(i, x.getPeg(i));
		
		//changing the genome in offspring based on reproductive process
		for(int i = index; i < numPegs; i++)
			offspring.setPeg(i, y.getPeg(i));
		
		//randomly switching the chromosome with another spot in the genome. helps with diversity
		int newIndex = generator.nextInt(numPegs);
		int oldPeg = offspring.getPeg(newIndex);
		offspring.setPeg(newIndex, offspring.getPeg(index));
		offspring.setPeg(index, oldPeg);
		
		//getting the fitness of the offspring
		fitness(offspring); 
		
		return offspring;
	}
	
	/**
	 * Method to determine the fitness of each organism based on how close it appears to the bestIndividual
	 * @param creature
	 * @return fitness
	 */
	private static double fitness(Organism individual){
		double fitness = 0;
		
		Organism test;
		
		test = bestIndividual;
		//for(int l = 0; l < priorGuessCount; l++){
			//test = priorGuesses[l];
			double numReds = 0;
			double numWhites = 0;
			//compare with bestIndividual
			for(int i = 0; i < individual.getSize(); i++){
				if(individual.getPeg(i) == test.getPeg(i))
					numReds++; //if the individual had a peg in the same place as our current best guess
			} 
		
			//need to keep track of pegs that we have seen so we don't double count the whites
			int[] visited = new int[numPegs];
			int count = 0;
		
			//counting up whites, reds are repeated
			for(int i = 0; i < numPegs; i++){	
				//if the current color appears in the bestIndividual the same number of time it appears in the individual we are testing and we have not already tested this color
				if(numRepetitions(test.getPeg(i), test) == numRepetitions(test.getPeg(i), individual) && !contains(test.getPeg(i), visited)){
					numWhites += numRepetitions(test.getPeg(i), individual);
					visited[count] = test.getPeg(i);
					count++;
				}
				//if the current color appears more times in bestIndividual than in the individual and we have not tested it before
				else if(numRepetitions(test.getPeg(i), test) > numRepetitions(test.getPeg(i), individual) && !contains(test.getPeg(i), visited)){
					numWhites += numRepetitions(test.getPeg(i), individual); //set it number of times it appears in the individual
					visited[count] = test.getPeg(i);
					count++;
				}
				//if the current color appears less times in bestIndividual than in the individual and we have not tested it before
				else if(numRepetitions(test.getPeg(i), test) < numRepetitions(test.getPeg(i), individual) && !contains(test.getPeg(i), visited)){
					numWhites += numRepetitions(test.getPeg(i), test); //set number of whites to the times it appears in the bestIndividual
					visited[count] = test.getPeg(i);
					count++;
				}
			}
			//subtracting off the number of reds that were double  counted
			numWhites -= numReds;
			//Fitness is a function of the number of reds and whites from prior guesses minus the number from the current individual.
			//fitness = Math.abs((numReds - test.getReds()))/numPegs + Math.abs((numWhites - test.getWhites()))/numPegs; 
			fitness = numReds + numWhites;
		//}
		fitness = fitness/numPegs;
		//fitness = Math.abs(1-fitness);
		/**
		fitness = (numReds/numPegs) + (numWhites/numPegs); //takes into account number of red pegs, and white pegs equally
		
		//if the individual has at least one of every color that the bestIndividual has, then give a small boost to the fitness
		double bonus = 0;
		for(int i = 0; i < count; i++){
			if(numRepetitions(visited[i], individual) >= 1)
				bonus += 1;
		}
		if(bonus == count) //if the unique colors already recorded are all in the individual add bonus
			fitness += 0.1;
		**/
		//if my individual has any pegs that aren't consitent with the best individual, subtract some off the fitness
		int negative = 0;
		for(int i = 0; i < numPegs; i++){
			if(numRepetitions(individual.getPeg(i), bestIndividual) <= 0)
				negative += 1;
		}
		if(negative >= 1)
			fitness -= 0.1;
		
		individual.setFitness(fitness); //remember to set fitness of individual
		
		return fitness;
	}//end method
	
	/**
	 * Method to determine the actual fitness by passing it as a guess
	 * @param individual
	 * @return double
	 */
	private static double actualFitness(Organism individual){
		/* this is last resort crap shoot */
		String[] guess = new String[individual.getSize()];
		String response;
		String[] received;
		
		guess = convertToString(individual); //translating our int array into proper format for sending guesses
		sendGuess(guess); //sending off our guess
		response = receiveResponse();
		received = response.split(",");
		double Reds = Integer.parseInt(received[0]); //determining number of reds
		double Whites = Integer.parseInt(received[1]); //determining number of whites
		double realfitness = Reds/numPegs + (Whites/(numPegs+1)); //calculating the fitness
		individual.setFitness(realfitness); //remember to set fitness of individual
		individual.setReds(Reds);
		individual.setWhites(Whites);
		return realfitness;
	} //end method
	
	/**
	 * Method to determine the number of times a peg is repeated in an individual
	 * @param peg
	 * @param individual
	 * @return int
	 */
	private static int numRepetitions(int peg, Organism individual){
		int reps = 0;
		for(int i = 0; i < individual.getSize(); i++){
			if(peg == individual.getPeg(i))
				reps++;
		}
		return reps;
	} //end method
	
	/**
	 * Method to test if the peg passed in is contained in the other creature's genome.
	 * @param peg test
	 * @return boolean
	 */
	private static boolean contains(int peg, int[] test){
		for(int i = 0; i < test.length; i++){
			if(peg == test[i])
				return true;
		}
		return false;
	}//end method
	
	/**
	 * Method to convert from the int[] type of genome in the Organism to the String[] of colors. Takes in an individual.
	 * @param individual
	 * @return String[]
	 */
	private static String[] convertToString(Organism individual){
		String[] colors = new String[individual.getSize()];
		
		for(int i = 0; i < individual.getSize(); i++){
			colors[i] = colorList[individual.getPeg(i)];
		}
		return colors;
	}//end class

}
