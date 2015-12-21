KNN (k-nearest neighbors)
===

C++ implementation of K-nearest neighbors. 
This was the first assignment of a Machine Learning course I took during my master's. The code is reasonably clean. However, it does not integrate with any 3rd-party matrix library, so if you want to use it, you may need to write adapters / change the references to the matrix class.

The main function:
* Reads the training and testing datasets
* Splits the training dataset into train and validation
* Use the validation set to choose the best K (number of neighbors to consider)
* Calculates:

  * Success rate for different K
  * Confusion Matrix
  * Top X success rate
