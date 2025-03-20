import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:myfinance/presentations/providers/transaction_provider.dart';
import 'package:image_picker/image_picker.dart'; // For image upload
import 'dart:io'; // For handling file paths

class CategoriesScreen extends StatelessWidget {
  const CategoriesScreen({super.key});

  @override
  Widget build(BuildContext context) {
    final transactionProvider = Provider.of<TransactionProvider>(context);

    return Scaffold(
      appBar: AppBar(
        iconTheme: const IconThemeData(color: Colors.white),
        backgroundColor: const Color.fromRGBO(83, 177, 117, 1),
        title: const Text(
          'Categories',
          style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
        ),
      ),
      body: transactionProvider.categories.isEmpty
          ? Center(
              child: Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  const Text(
                    'Empty ! Add Categories',
                    style: TextStyle(
                        fontSize: 18,
                        fontWeight: FontWeight.bold,
                        color: Colors.grey),
                  ),
                  const SizedBox(height: 16),
                ],
              ),
            )
          : GridView.builder(
              padding: const EdgeInsets.all(16),
              gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                crossAxisCount: 2, // 2 items per row
                crossAxisSpacing: 16, // Spacing between columns
                mainAxisSpacing: 16, // Spacing between rows
                childAspectRatio: 1, // Square shape
              ),
              itemCount: transactionProvider.categories.length,
              itemBuilder: (ctx, index) {
                final category = transactionProvider.categories[index];
                return Card(
                  elevation: 4,
                  shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(8),
                  ),
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      if (category.imagePath != null)
                        ClipRRect(
                          borderRadius: BorderRadius.circular(8),
                          child: category.imagePath!.startsWith('assets/')
                              ? Image.asset(
                                  category.imagePath!,
                                  width: 80,
                                  height: 80,
                                  fit: BoxFit.cover,
                                )
                              : Image.file(
                                  File(category.imagePath!),
                                  width: 80,
                                  height: 80,
                                  fit: BoxFit.cover,
                                ),
                        )
                      else
                        const Icon(Icons.category, size: 80),
                      const SizedBox(height: 8),
                      Text(
                        category.name,
                        style: const TextStyle(
                            fontSize: 16, fontWeight: FontWeight.bold),
                      ),
                    ],
                  ),
                );
              },
            ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          _showAddCategoryBottomSheet(context, transactionProvider);
        },
        backgroundColor: Color.fromRGBO(83, 177, 117, 1),
        child: const Icon(
          Icons.add,
          color: Colors.white,
        ),
      ),
    );
  }

  // Function to Show Bottom Sheet for Adding Category
  void _showAddCategoryBottomSheet(
      BuildContext context, TransactionProvider transactionProvider,
      {String? initialCategoryName, String? initialImagePath}) {
    String categoryName = initialCategoryName ?? '';
    String? imagePath = initialImagePath;

    // List of default images (asset paths)
    final List<String> defaultImages = [
      'assets/default_images/food.png',
      'assets/default_images/transport.png',
      'assets/default_images/shopping.png',
      'assets/default_images/entertainment.png',
      'assets/default_images/health.png',
    ];

    showModalBottomSheet(
      context: context,
      isScrollControlled: true,
      builder: (context) {
        return Padding(
          padding: EdgeInsets.only(
            bottom: MediaQuery.of(context).viewInsets.bottom,
          ),
          child: SingleChildScrollView(
            child: Column(
              mainAxisSize: MainAxisSize.min,
              children: [
                const SizedBox(height: 16),
                const Text(
                  'Add Category',
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
                ),
                const SizedBox(height: 16),
                TextField(
                  onChanged: (value) {
                    categoryName = value;
                  },
                  decoration: const InputDecoration(
                    labelText: 'Category Name',
                    border: OutlineInputBorder(),
                  ),
                  controller: TextEditingController(text: initialCategoryName),
                ),
                const SizedBox(height: 16),
                const Text(
                  'Choose a Default Image or Upload Your Own',
                  style: TextStyle(fontSize: 16),
                ),
                const SizedBox(height: 16),
                // Grid of Default Images
                GridView.builder(
                  shrinkWrap: true,
                  physics: const NeverScrollableScrollPhysics(),
                  gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                    crossAxisCount: 3, // 3 items per row
                    crossAxisSpacing: 8,
                    mainAxisSpacing: 8,
                  ),
                  itemCount: defaultImages.length,
                  itemBuilder: (context, index) {
                    return GestureDetector(
                      onTap: () {
                        // Set the selected default image
                        imagePath = defaultImages[index];
                        Navigator.of(context).pop(); // Close the bottom sheet
                        _showAddCategoryBottomSheet(
                            context, transactionProvider,
                            initialCategoryName: categoryName,
                            initialImagePath:
                                imagePath); // Reopen with selected image
                      },
                      child: ClipRRect(
                        borderRadius: BorderRadius.circular(8),
                        child: Image.asset(
                          defaultImages[index],
                          width: 60,
                          height: 60,
                          fit: BoxFit.cover,
                        ),
                      ),
                    );
                  },
                ),
                const SizedBox(height: 16),
                // Upload Image Button
                TextButton(
                  child: const Text('Upload Image from Gallery'),
                  onPressed: () async {
                    final picker = ImagePicker();
                    final pickedFile = await picker.pickImage(
                      source: ImageSource.gallery,
                    );
                    if (pickedFile != null) {
                      imagePath = pickedFile.path;
                      Navigator.of(context).pop(); // Close the bottom sheet
                      _showAddCategoryBottomSheet(context, transactionProvider,
                          initialCategoryName: categoryName,
                          initialImagePath:
                              imagePath); // Reopen with uploaded image
                    }
                  },
                ),
                const SizedBox(height: 16),
                // Display Selected Image
                if (imagePath != null)
                  imagePath!.startsWith('assets/')
                      ? Image.asset(
                          imagePath!,
                          width: 100,
                          height: 100,
                          fit: BoxFit.cover,
                        )
                      : Image.file(
                          File(imagePath!),
                          width: 100,
                          height: 100,
                          fit: BoxFit.cover,
                        ),
                const SizedBox(height: 16),
                // Add Category Button
                ElevatedButton(
                  onPressed: () {
                    if (categoryName.isNotEmpty) {
                      transactionProvider.addCategory(
                        categoryName,
                        imagePath: imagePath,
                      );
                      Navigator.of(context).pop(); // Close the bottom sheet
                    } else {
                      ScaffoldMessenger.of(context).showSnackBar(
                        const SnackBar(
                            content: Text('Please enter a category name')),
                      );
                    }
                  },
                  style: ElevatedButton.styleFrom(
                    backgroundColor: Color.fromRGBO(83, 177, 117, 1),
                  ),
                  child: const Text(
                    'Add Category',
                    style: TextStyle(color: Colors.white),
                  ),
                ),
                const SizedBox(height: 16),
              ],
            ),
          ),
        );
      },
    );
  }
}
