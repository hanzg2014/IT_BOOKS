def pi(nsteps):
    sum, step = 0.0, 1.0 / nsteps
    for i in range(nsteps):
        x = (i - 0.5) * step
        sum += 4.0 / (1.0 + x**2)
    return step * sum
