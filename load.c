#include <stdio.h>

// Define a structure to hold your data
typedef struct
{
    int intValue;
    float floatValue;
    char stringValue[50];
} Data;

// Function to save data to a file
void saveData(const Data *data, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("Error opening file for writing");
        return;
    }

    // Write the data to the file
    fwrite(data, sizeof(Data), 1, file);

    // Close the file
    fclose(file);
}

// Function to load data from a file
void loadData(Data *data, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("Error opening file for reading");
        return;
    }

    // Read the data from the file
    fread(data, sizeof(Data), 1, file);

    // Close the file
    fclose(file);
}

int main()
{
    // Create an instance of the Data structure
    Data myData = {42, 3.14, "Hello, World!"};

    // Save the data to a file
    saveData(&myData, "datafile.dat");

    // Create another instance to load the data into
    Data loadedData;

    // Load the data from the file
    loadData(&loadedData, "datafile.dat");

    // Display the loaded data
    printf("Loaded Data:\n");
    printf("Integer Value: %d\n", loadedData.intValue);
    printf("Float Value: %f\n", loadedData.floatValue);
    printf("String Value: %s\n", loadedData.stringValue);

    return 0;
}
