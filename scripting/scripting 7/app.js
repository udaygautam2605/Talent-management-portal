document.getElementById("location-form").addEventListener("submit", function(event) {
    event.preventDefault(); // Prevent default form submission
    
    // Get the user input location
    const location = document.getElementById("location-input").value;
    
    // Call the function to fetch weather data
    getWeatherData(location);
    });
    
    function getWeatherData(location) {
    const apiKey = "e7d90ada6a507c89c1a10973b458546c";
    const apiUrl = `https://api.openweathermap.org/data/2.5/weather?q=${location}&appid=${apiKey}&units=metric`;
    
    // Make an AJAX request
    fetch(apiUrl)
    .then(response => response.json())
    .then(data => {
    const { main, weather, wind, sys } = data;
    const country = sys && sys.country ? sys.country : "";
    const weatherInfo = document.getElementById("weather-info");
    weatherInfo.innerHTML = `
    <h2>${data.name}, ${country}</h2>
    <p>Temperature: ${main.temp} °C</p>
    <p>Weather: ${weather[0].description}</p>
    <p>Humidity: ${main.humidity}%</p>
    <p>Wind Speed: ${wind.speed} m/s</p>
    `;
    })
    .catch(error => {
    console.error('Error fetching weather data:', error);
    document.getElementById("weather-info").innerHTML = "Unable to fetch weather data. Please try again later.";
    });
    }
    