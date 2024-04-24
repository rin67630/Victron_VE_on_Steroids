{
	"controls": {
		"aggregation": {
			"auto": false,
			"period": "auto"
		},
		"timespan": {
			"magnitude": "day",
			"mode": "relative",
			"period": "latest",
			"value": 2
		}
	},
	"description": "Frontpage",
	"name": "Frontpage",
	"properties": {
		"background_image": "#000000",
		"border_radius": "10px",
		"columns": 5,
		"hide_header": true,
		"row_height": 24
	},
	"tabs": [
		{
			"icon": "fas fa-tachometer-alt",
			"name": "Test2",
			"widgets": [
				{
					"layout": {
						"col": 4,
						"row": 0,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"currentColor": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Half Voltage"
					},
					"properties": {
						"color": "#01df23",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "BatV",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "Vac",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 10,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"currentColor": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Yesterday Ah"
					},
					"properties": {
						"color": "#808000",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "Iac",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"device_property": {
								"device": "Steroids",
								"mapping": "Yesterday",
								"property": "statAh"
							},
							"name": "Iac",
							"skipCurrent": 1,
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 0,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Battery Voltage"
					},
					"properties": {
						"color": "#01df23",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "BatV",
								"resource": "MIN",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "Vbat",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 0,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Load Voltage"
					},
					"properties": {
						"color": "#01df23",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "BatV",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "Vaux",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 0,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Panel Voltage"
					},
					"properties": {
						"color": "#f8ff38",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "V",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "PanV",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "Vpan",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 5,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Battery Current"
					},
					"properties": {
						"color": "#df3e12",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "A",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "BatI",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "Ibat",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 5,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Load Current"
					},
					"properties": {
						"color": "#df3e12",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "A",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "LodI",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "Iaux",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 5,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Panel Current"
					},
					"properties": {
						"color": "#df3e12",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "A",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "PanI",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "IPan",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 10,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Panel Power"
					},
					"properties": {
						"color": "#4852df",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "W",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "PanW",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "Wpan",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 10,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Battery Power"
					},
					"properties": {
						"color": "#4852df",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "W",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "BatW",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "Wbat",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 10,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Load Power"
					},
					"properties": {
						"color": "#4852df",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "W",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "LodW",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "Waux",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 5,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"currentColor": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Battery int. Resistance"
					},
					"properties": {
						"color": "#a3690f",
						"decimal_places": 1,
						"icon": "",
						"size": "75px",
						"unit": "mΩ",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "Iohm",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "ohm",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 10,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"currentColor": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "% Charged"
					},
					"properties": {
						"color": "#efae36",
						"decimal_places": 0,
						"icon": "",
						"size": "75px",
						"unit": "%",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "ChSt",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"name": "percent_charged",
							"skipCurrent": 1,
							"source": "device"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 4,
						"row": 54,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#808080",
						"showOffline": {
							"type": "none"
						},
						"title": "Weather"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "36px",
						"unit": "",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "Steroids",
								"mapping": "summary",
								"property": "persistance",
								"user": "rin67631"
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 54,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#808080",
						"title": "Outside rel. humidity"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "75px",
						"unit": "%",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "Steroids",
								"mapping": "humidity",
								"property": "persistance",
								"user": "rin67631"
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 1,
						"row": 54,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#808080",
						"title": "Outside Temperature"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "75px",
						"unit": "°C",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "Steroids",
								"mapping": "temperature",
								"property": "persistance",
								"user": "rin67631"
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 2,
						"row": 54,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#808080",
						"title": "Atm. Pressure"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "75px",
						"unit": "hPa",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "Steroids",
								"mapping": "pressure",
								"property": "persistance",
								"user": "rin67631"
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 3,
						"row": 54,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#808080",
						"title": "Wind"
					},
					"properties": {
						"color": "#1E313E",
						"decimal_places": 0,
						"icon": "",
						"size": "75px",
						"unit": "m/s",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device_property": {
								"device": "Steroids",
								"mapping": "wind",
								"property": "persistance",
								"user": "rin67631"
							},
							"source": "device_property"
						}
					],
					"type": "text"
				},
				{
					"layout": {
						"col": 0,
						"row": 15,
						"sizeX": 5,
						"sizeY": 39
					},
					"panel": {
						"color": "#2c2c2c",
						"colors": [],
						"currentColor": "#2c2c2c",
						"showOffline": {
							"type": "none"
						}
					},
					"properties": {
						"axis": true,
						"fill": false,
						"legend": true,
						"multiple_axes": false,
						"yaxis": {
							"min": ""
						}
					},
					"sources": [
						{
							"aggregation": {},
							"bucket": {
								"backend": "dynamodb",
								"id": "MIN",
								"mapping": "BatI",
								"tags": {},
								"user": "rin67631"
							},
							"color": "#fd5a02",
							"name": "Bat Amperes",
							"source": "bucket",
							"timespan": {
								"magnitude": "day",
								"mode": "configurable",
								"period": "latest",
								"value": 2
							}
						},
						{
							"aggregation": {},
							"bucket": {
								"backend": "dynamodb",
								"id": "MIN",
								"mapping": "BatV",
								"user": "rin67631"
							},
							"color": "#0df525",
							"name": "Batt Volts",
							"source": "bucket",
							"timespan": {
								"magnitude": "day",
								"mode": "configurable",
								"period": "latest",
								"value": 2
							}
						},
						{
							"aggregation": {},
							"bucket": {
								"backend": "dynamodb",
								"id": "MIN",
								"mapping": "BatW",
								"user": "rin67631"
							},
							"color": "#4463ff",
							"name": "Bat Watts",
							"source": "bucket",
							"timespan": {
								"magnitude": "day",
								"mode": "configurable",
								"period": "latest",
								"value": 2
							}
						}
					],
					"type": "chart"
				},
				{
					"layout": {
						"col": 3,
						"row": 0,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"currentColor": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Last Hour  Ah"
					},
					"properties": {
						"color": "#808000",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"bucket": {
								"backend": "dynamodb",
								"id": "MIN",
								"mapping": "BatAh",
								"tags": {}
							},
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "Iac",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"device_property": {
								"device": "Steroids",
								"mapping": "Today",
								"property": "statAh"
							},
							"name": "Iac",
							"skipCurrent": 1,
							"source": "bucket",
							"timespan": {
								"mode": "latest"
							}
						}
					],
					"type": "text"
				},
				{
					"$loadAttemps": 205,
					"layout": {
						"col": 3,
						"row": 5,
						"sizeX": 1,
						"sizeY": 5
					},
					"panel": {
						"color": "#404040",
						"currentColor": "#404040",
						"showOffline": {
							"type": "none"
						},
						"title": "Today Ah"
					},
					"properties": {
						"color": "#808000",
						"decimal_places": 2,
						"icon": "",
						"size": "75px",
						"unit": "Ah",
						"unit_size": "20px",
						"weight": "font-thin"
					},
					"sources": [
						{
							"device": {
								"id": "Steroids",
								"interval": 5,
								"mapping": "Iac",
								"resource": "measure",
								"update": "interval",
								"user": "rin67631"
							},
							"device_property": {
								"device": "Steroids",
								"mapping": "Today",
								"property": "statAh"
							},
							"name": "Iac",
							"skipCurrent": 1,
							"source": "device_property"
						}
					],
					"type": "text"
				}
			]
		}
	],
	"widgets": [],
	"placeholders": {
		"sources": []
	}
}
