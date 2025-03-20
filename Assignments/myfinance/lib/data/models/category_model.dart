class Category {
  final String id;
  final String name;
  final String? imagePath; // Add this field

  Category({
    required this.id,
    required this.name,
    this.imagePath,
  });
}
