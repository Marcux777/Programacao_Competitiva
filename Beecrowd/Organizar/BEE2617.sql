SELECT prod.name AS product_name, prov.name AS provider_name
FROM products prod
JOIN providers prov ON prov.id = prod.id_providers
WHERE prov.name = 'Ajax SA';
