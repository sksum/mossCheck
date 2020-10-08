<script>
	export let callBack;
	let value
</script>
<div>
<label for="userID">userID</label>
<input type="number" id="userID" name="userID" min="0"> 
<form action="/action_page.php" on:submit={callBack}>
    <label for="language">Choose a Language:</label>
    <select id="language" name="language" bind:value={value} on:change={(evt)=>callBack(evt,value)}>
      <option value="cc">C++</option>
      <option value="c">C</option>
      <option value="js">Javascript</option>
      <option value="py">Python</option>
	  <option value="java">Java</option>
	  <option value="haskell">Haskell</option>
	  <option value="fortran">Fortran</option>
	  <option value="csharp">C#</option>
	  <option value="vb">Visual Basic</option>
    </select>
</form>
</div>
<style>

	label {
		color: #186896;
		text-transform: uppercase;
		font-size: 1em;
		font-weight: 20;
	}
	div {
		text-align: center;
		padding: 1em;
		max-width: 240px;
		margin: 0 auto;
	}

</style>