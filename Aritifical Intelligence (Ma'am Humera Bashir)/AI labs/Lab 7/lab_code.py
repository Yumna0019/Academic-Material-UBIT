import random
import numpy as np
import operator
from deap import base, creator, tools, gp

# Define the target equation: 5X^3 - 6X^2 + 8X = 1
def target_equation(x):
    return 5 * x ** 3 - 6 * x ** 2 + 8 * x

# Define protected division to avoid division by zero
def protected_div(x, y):
    if y == 0:
        return 1
    return x / y

# Define the evaluation function for symbolic regression
def eval_func(individual):
    func = toolbox.compile(expr=individual)
    error = 0.0
    for x in range(1, 11):  # Evaluate for x from 1 to 10
        error += abs(target_equation(x) - func(x))
    return error / 10,  # Return the average error

# Create the toolbox with the right parameters
def create_toolbox():
    creator.create("FitnessMin", base.Fitness, weights=(-1.0,))
    creator.create("Individual", gp.PrimitiveTree, fitness=creator.FitnessMin)

    # Initialize the toolbox
    toolbox = base.Toolbox()

    # Register the primitives
    pset = gp.PrimitiveSet("MAIN", arity=1)
    pset.addPrimitive(operator.add, arity=2)
    pset.addPrimitive(operator.sub, arity=2)
    pset.addPrimitive(operator.mul, arity=2)
    pset.addPrimitive(protected_div, arity=2)  # Add protected_div
    pset.addTerminal(1, name="1")  # Constant terminal
    pset.renameArguments(ARG0="X")

    # Define the toolbox
    toolbox.register("expr", gp.genHalfAndHalf, pset=pset, min_=1, max_=2)
    toolbox.register("individual", tools.initIterate, creator.Individual, toolbox.expr)
    toolbox.register("population", tools.initRepeat, list, toolbox.individual)
    toolbox.register("compile", gp.compile, pset=pset)
    toolbox.register("evaluate", eval_func)
    toolbox.register("mate", gp.cxOnePoint)
    toolbox.register("expr_mut", gp.genFull, min_=0, max_=2)
    toolbox.register("mutate", gp.mutUniform, expr=toolbox.expr_mut, pset=pset)
    toolbox.register("select", tools.selTournament, tournsize=3)

    return toolbox

if __name__ == "__main__":
    toolbox = create_toolbox()
    random.seed(7)
    population = toolbox.population(n=500)
    probab_crossing, probab_mutating = 0.5, 0.2
    num_generations = 10
    print("\nEvolution process starts")

    # Evaluate the entire population
    fitnesses = list(map(toolbox.evaluate, population))
    for ind, fit in zip(population, fitnesses):
        ind.fitness.values = fit
    print("\nEvaluated", len(population), "individuals")

    # Create and iterate through generations
    for g in range(num_generations):
        print("\n- Generation", g)
        # Select the next generation individuals
        offspring = toolbox.select(population, len(population))
        # Clone the selected individuals
        offspring = list(map(toolbox.clone, offspring))

        # Apply crossover and mutation on the offspring
        for child1, child2 in zip(offspring[::2], offspring[1::2]):
            if random.random() < probab_crossing:
                toolbox.mate(child1, child2)
                del child1.fitness.values
                del child2.fitness.values

        # Apply mutation
        for mutant in offspring:
            if random.random() < probab_mutating:
                toolbox.mutate(mutant)
                del mutant.fitness.values

        # Evaluate the individuals with an invalid fitness
        invalid_ind = [ind for ind in offspring if not ind.fitness.valid]
        fitnesses = map(toolbox.evaluate, invalid_ind)
        for ind, fit in zip(invalid_ind, fitnesses):
            ind.fitness.values = fit

        print("\nEvaluated", len(invalid_ind), "individuals")

        # Replace population with the next generation individual
        population[:] = offspring

        # Print the statistics for the current generation
        fits = [ind.fitness.values[0] for ind in population]

        length = len(population)
        mean = sum(fits) / length
        sum2 = sum(x * x for x in fits)
        std = abs(sum2 / length - mean ** 2) ** 0.5

        print("Min =", min(fits), ", Max =", max(fits))
        print("Average =", round(mean, 2), ", Standard deviation =", round(std, 2))

    # Print the final output
    print("\nEvolution ends")
    best_ind = tools.selBest(population, 1)[0]
    print('\nBest individual:\n', best_ind)
