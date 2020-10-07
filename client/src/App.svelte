<script>
	import Toolbar from './Toolbar.svelte'
	import EditorContainer from './EditorContainer.svelte'
	let language = "cc";

	let callBack = (evt,lang) => {
		language = lang;
		evt.preventDefault() 
	}
</script>

<main>
	<Toolbar {callBack}/>
	<EditorContainer lang={language}/>
</main>

<style>
	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}
</style>