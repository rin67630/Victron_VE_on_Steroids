{
	"description": "Statistics",
	"name": "Statistics",
	"placeholders": {
		"sources": []
	},
	"properties": {
		"border_radius": "10px",
		"columns": 9,
		"row_height": 26
	},
	"tabs": [
		{
			"icon": "fas fa-tachometer-alt",
			"name": "Statistics",
			"widgets": [
				{
					"layout": {
						"col": 6,
						"row": 0,
						"sizeX": 3,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "Other statistics"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 2,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "Yesterday"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 0,
						"sizeX": 6,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "Hourly statistics"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 50,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From23:00to23:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "D-7"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 2,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 50,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B23V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 2,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": ""
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 50,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B23Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 2,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": ""
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 2,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "To/from Battery"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 6,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "Today"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 4,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From00:00to00:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B00Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B00V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 6,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From01:00to01:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 6,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "01h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 6,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "01h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 6,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B01Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 6,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B01V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 8,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From02:00to02:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "02h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "02h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B02Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B02V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 10,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From03:00to03:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "03h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "03h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B03Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B03V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 12,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From04:00to04:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 12,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "04h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 12,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "04h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 12,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B04Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 12,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B04V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 50,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "23h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 50,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "23h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "LastHour",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-7",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "LastHour",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 14,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From05:00to05:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "05h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "05h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B05Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B05V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"$loadAttemps": 26,
					"layout": {
						"col": 0,
						"row": 18,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From07:00to07:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 16,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From06:00to06:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 18,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "07h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "06h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 18,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "07h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "06h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 18,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B07Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B06Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 18,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B07V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B06V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 20,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From08:00to08:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "08h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "08h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B08Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B08V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 22,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From09:00to09:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 22,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "09h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 22,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "09h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 22,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B09Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 22,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B09V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 24,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From10:00to10:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 24,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "10h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 24,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "10h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 24,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B10Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 24,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B10V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "Yesterday"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 6,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "Today",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 6,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "Today",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 20,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-7",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 26,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From11:00to11:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 26,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "11h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 26,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "11h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 26,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B11Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 26,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B11V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 28,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From12:00to12:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 28,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "12h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 28,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "12h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 28,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B12Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 28,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B12V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 30,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From13:00to13:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 30,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "13h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 30,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "13h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 30,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B13Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 30,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B13V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 32,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From14:00to14:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 32,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "14h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 32,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "14h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 32,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B14Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 32,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B14V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 34,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From15:00to15:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 34,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "15h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 34,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "15h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 34,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B15Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 34,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B15V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 36,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From16:00to16:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 36,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "16h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 36,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "16h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 36,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B16Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 36,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B16V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 38,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From17:00to17:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 38,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "17h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 38,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "17h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 38,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B17Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 38,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B18V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 40,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From18:00to18:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 40,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "18h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 40,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "18h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 40,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B18Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 40,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B18V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 42,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From19:00to19:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 42,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "19h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 42,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "19h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 42,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B19Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 42,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B19V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 44,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From20:00to20:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 44,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "20h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 44,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B20Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 44,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B20V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 44,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "20h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 18,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "D-6"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "D-5"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "D-4"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 12,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "D-3"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "D-2"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 18,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-6",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-5",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-4",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 12,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-3",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-2",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 7,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "HOUR",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "Yesterday",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 18,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-6",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 16,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-5",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 14,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-4",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 10,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-2",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 12,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "D-3",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 8,
						"row": 8,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "Yesterday",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 48,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From22:00to22:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 46,
						"sizeX": 2,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "From21:00to21:59"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 48,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "22h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 46,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "21h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 48,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "22h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 46,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "21h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "device_property",
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 48,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B22Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 46,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#ff8040",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B21Ah",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statAh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 48,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B22V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 5,
						"row": 46,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#ffffff",
						"currentColor": "#ffffff",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#008000",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "DAY",
								"mapping": "B21V",
								"tags": {}
							},
							"color": "#1abc9c",
							"device_property": {
								"device": "Steroids",
								"mapping": "00h",
								"property": "statVh"
							},
							"name": "Source 1",
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							},
							"value": "Current Day"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 6,
						"row": 4,
						"sizeX": 1,
						"sizeY": 2
					},
					"panel": {
						"color": "#808080",
						"currentColor": "#808080",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 2,
						"icon": "",
						"size": "32px",
						"unit_size": "20px",
						"weight": "font-normal"
					},
					"sources": [
						{
							"color": "#1abc9c",
							"name": "Source 1",
							"source": "value",
							"value": "Last Hour"
						}
					],
					"type": "text"
				}
			]
		}
	],
	"widgets": []
}
