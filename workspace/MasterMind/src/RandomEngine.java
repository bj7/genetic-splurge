/**
 * 
 */
import java.util.Random;
/**
 * @author jjbernitt
 * This class is designed to implement a random number engine
 *
 */
public class RandomEngine {
	//seeds for either ints or doubles
	private int seed;
	private double dseed;
	
	/**
	 * Default constructor
	 */
	public RandomEngine(){
		Random sseed = new Random();
		seed = sseed.nextInt();
		dseed = sseed.nextDouble();
	}//default constructor
	
	/**
	 * Constructor for an integer seed value
	 * @param seed
	 */
	public RandomEngine(int seed){
		this.seed = seed;
	}//constructor for ints
	
	/**
	 * Constructor for a double seed value
	 * @param seed
	 */
	public RandomEngine(double seed){
		this.dseed = seed;
	}//constructor for doubles
	
	/**
	 * Method to create a random int within the range passed into it
	 * @param seed
	 * @return int
	 */
	public int nextInt(int seed){
		this.seed = seed;
		int random = 0;
		Random generate = new Random();
		
		//randomly select how many iterations to perform, with the last iteration being equal to a random number
		for(int i = 0; i < generate.nextInt(100); i++)
			random = generate.nextInt(seed);
		
		//10% chance that we will randomly change it
		if(generate.nextInt(10) == 1)
			random = generate.nextInt(seed);
		
		//some bizar chance of re-evaluating my random
		if((generate.nextGaussian()*seed)%generate.nextGaussian() >= generate.nextDouble())
			random = generate.nextInt(seed);
		
		return random;
	}//end method
	
}//end class
