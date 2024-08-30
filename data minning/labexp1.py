import pandas as pd

# Load the Wine dataset
wine_df = pd.read_csv('/Users/uday/Downloads/wine.csv')

# Load the Housing dataset
housing_df = pd.read_csv('/Users/uday/Downloads/housing.csv')

# Preview the datasets
print("Wine Dataset Preview:")
print(wine_df.head())
print("\nHousing Dataset Preview:")
print(housing_df.head())

# Central Tendency for Wine dataset
numeric_wine = wine_df.select_dtypes(include='number')
mean_wine = numeric_wine.mean()
median_wine = numeric_wine.median()
mode_wine = numeric_wine.mode().iloc[0]

# Central Tendency for Housing dataset
numeric_housing = housing_df.select_dtypes(include='number')
mean_housing = numeric_housing.mean()
median_housing = numeric_housing.median()
mode_housing = numeric_housing.mode().iloc[0]

# Dispersion for Wine dataset
range_wine = numeric_wine.max() - numeric_wine.min()
quartiles_wine = numeric_wine.quantile([0.25, 0.5, 0.75])
iqr_wine = quartiles_wine.loc[0.75] - quartiles_wine.loc[0.25]
variance_wine = numeric_wine.var()
std_dev_wine = numeric_wine.std()

# Dispersion for Housing dataset
range_housing = numeric_housing.max() - numeric_housing.min()
quartiles_housing = numeric_housing.quantile([0.25, 0.5, 0.75])
iqr_housing = quartiles_housing.loc[0.75] - quartiles_housing.loc[0.25]
variance_housing = numeric_housing.var()
std_dev_housing = numeric_housing.std()

# Covariance and Correlation Matrix for Wine dataset
cov_matrix_wine = numeric_wine.cov()
corr_matrix_wine = numeric_wine.corr()

# Covariance and Correlation Matrix for Housing dataset
cov_matrix_housing = numeric_housing.cov()
corr_matrix_housing = numeric_housing.corr()

print("\nWine Dataset Statistics:")
print("Mean:\n", mean_wine)
print("Median:\n", median_wine)
print("Mode:\n", mode_wine)
print("Range:\n", range_wine)
print("IQR:\n", iqr_wine)
print("Variance:\n", variance_wine)
print("Standard Deviation:\n", std_dev_wine)
print("Covariance Matrix:\n", cov_matrix_wine)
print("Correlation Matrix:\n", corr_matrix_wine)

print("\nHousing Dataset Statistics:")
print("Mean:\n", mean_housing)
print("Median:\n", median_housing)
print("Mode:\n", mode_housing)
print("Range:\n", range_housing)
print("IQR:\n", iqr_housing)
print("Variance:\n", variance_housing)
print("Standard Deviation:\n", std_dev_housing)
print("Covariance Matrix:\n", cov_matrix_housing)
print("Correlation Matrix:\n", corr_matrix_housing)
