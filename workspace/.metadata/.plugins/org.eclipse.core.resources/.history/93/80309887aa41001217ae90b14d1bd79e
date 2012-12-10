/**
 * This file implements an object for individual organisms.
 */

/**
 * @author joshbernitt
 *
 */
public class Organism {
	
	//private variables for organism class 
	private int size;
	private int[] genome;
	private double fitness;
	
	/**
	 * Default constructor
	 * @param none
	 * @return none
	 */
	public Organism(){
		size = 0;
		fitness = 0;
		genome = new int[size];
	}//end default constructor
	
	/**
	 * Constructor for organism when defining size. Takes in an int
	 * argument to declare the genome to be of a certain size.
	 * @param size
	 * @return none 
	 */
	public Organism(int size){
		this.size = size;
		genome = new int[size];
	}//end constructor
	
	/**
	 * This method returns the key held at the desired index
	 * @param index
	 * @return genome[index]
	 */
	public int getPeg(int index){
		return genome[index];
	}//end function
	
	/**
	 * Method to set the peg at the desired index
	 * @param index
	 * @param peg
	 * @return none
	 */
	public void setPeg(int index, int peg){
		genome[index] = peg;
	}//end function
	
	/**
	 * Method to return the size of the genome
	 * @return size of genome
	 */
	public int getSize(){
		return genome.length;
	}//end method
	
	/**
	 * Method to set the fitness of the organism as determined 
	 * by the fitness function
	 * @param fitness
	 */
	public void setFitness(double fitness){
		this.fitness = fitness;
	}//end method
	
	/**
	 * Method to return the fitness of the organism
	 * @return fitness
	 */
	public double getFitness(){
		return fitness;
	}//end method

}//end class
