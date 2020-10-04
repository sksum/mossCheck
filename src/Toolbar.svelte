<script>
</script>

<label for="userID">userID</label>
<input type="number" id="userID" name="userID" min="0"> 
<form action="/action_page.php">
    <label for="language">Choose a Language:</label>
    <select id="language" name="language">
      <option value="cc">C++</option>
      <option value="c">C</option>
      <option value="js">Javascript</option>
      <option value="py">Python</option>
    </select>
    <input type="submit" value="Save">
  </form>

<style>

	label {
		color: #186896;
		text-transform: uppercase;
		font-size: 1em;
		font-weight: 20;
	}

	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}
</style>